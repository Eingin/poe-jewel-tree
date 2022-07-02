use promptly::prompt;

use crate::rng::RNG;

mod dat;
mod rng;

fn main() {
    let tree_version_id: u32 = 1;
    let jewel_seed: u32 = 5797;

    let skill_tree: dat::SkillTree = dat::load_json("data/SkillTree.json");

    let tree_versions: Vec<dat::AlternateTreeVersion> = dat::load_json("data/AlternateTreeVersions.json");
    let replacement_skills: Vec<dat::AlternatePassiveSkill> = dat::load_json("data/AlternatePassiveSkills.json");
    // let additional_skills: Vec<dat::AlternatePassiveAddition> = dat::load_json("data/AlternatePassiveAdditions.json");

    let node_id: u32 = prompt("Enter a node Id: ").expect("Expected user input");
    let node_key = node_id.to_string();

    if !skill_tree.nodes.contains_key(&node_key) {
        println!("Invalid node id");
        return;
    }

    let tree_node = &skill_tree.nodes[&node_key];

    let tree_version = tree_versions.iter().find(|version| version._rid == tree_version_id).unwrap();
    let filtered: Vec<&dat::AlternatePassiveSkill> = replacement_skills.iter()
    .filter(|skill| skill.alternate_tree_versions_key == tree_version_id) // Filter our tree version
    .filter(|skill| skill.passive_type.contains(&tree_node.get_pasive_type())) // Filter for node type. 1 = small attrib, 2 = small, 3 = notable, 4 = keystone 
    .collect();


    let seed = [node_id, jewel_seed];
    let rng = rng::build_poe_rng(seed);

    let should_replace: bool = match tree_node.get_pasive_type() {
        1 => tree_version.replace_attribute_nodes,
        2 => tree_version.replace_small_nodes,
        3 => {
            let chance = rng.next(100);
            tree_version.replace_chance >= 100 || chance < tree_version.replace_chance
        },
        4 => true,
        _=> false
    };

    if should_replace {
        let mut selected: Option<&dat::AlternatePassiveSkill> = None;
        let mut cumulative_weight: i32 = 0;


        for skill in filtered {
            if skill.spawn_weight == 0 {
                continue;
            }
            let new_weight: i32 = cumulative_weight + skill.spawn_weight;
            let rand_value = rng.next(new_weight);

            if rand_value < skill.spawn_weight {
                selected = Some(skill);
            }
            cumulative_weight = new_weight;

            // println!("{:?} {:?} {:?}", skill.Id, rand_value, skill.SpawnWeight);
            // println!("--------------------------------------");
        }

        let selected_replacement = selected.unwrap();
        let stat_values: Vec<i32> = selected_replacement.stats_keys.iter().enumerate().map(|i| {
            return match i.0 {
                0 => rng.next_range(selected_replacement.stat1_min, selected_replacement.stat1_max),
                1 => rng.next_range(selected_replacement.stat2_min, selected_replacement.stat2_max),
                _ => 0
            }
        }).collect();

        println!("{:?} {:?} {:?}", selected_replacement.name, selected_replacement.id, stat_values);   
    } else {
        println!("No replacement");
    }
    // TODO node additions
}
