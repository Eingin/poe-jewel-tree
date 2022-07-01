
use std::fs::File;
use std::io::Read;
use serde::{Deserialize, Serialize};

#[link(name = "poerng")]
extern {
    fn tintmt_init(state: *const u32, seed: *const u32) -> u32;
    fn tintmt_next(state: *const u32, max: u32) -> u32;
}


#[derive(Serialize, Deserialize, Debug)]
struct AlternatePassiveSkill {
    Id: String,
    AlternateTreeVersionsKey: i32,
    Name: String,
    SpawnWeight: u32,
    PassiveType: Vec<i32>,
}

struct PoeRng {
    state: [u32; 5],
    seed: [u32; 2]
}

trait RNG {
    fn next(&self, max: u32) -> u32;
}

impl RNG for PoeRng {
    fn next(&self, max: u32) -> u32 {
        let mut value: u32 = 0;
        unsafe {
            value = tintmt_next(&self.state[0], max);
        }
        return value;
    }
}

fn build_poe_rng(seed: [u32; 2]) -> PoeRng {
    let rng = PoeRng {
        state:  [0; 5],
        seed: seed,
    };
    unsafe {
        tintmt_init(&rng.state[0], &rng.seed[0]);
    }
    return rng;
}

fn main() {

    let mut file = File::open("AlternatePassiveSkills.json").unwrap();
    let mut data = String::new();
    file.read_to_string(&mut data).unwrap();

    let skills: Vec<AlternatePassiveSkill> = serde_json::from_str(&data).unwrap();

    
    let filtered: Vec<&AlternatePassiveSkill> = skills.iter()
    .filter(|skill| skill.AlternateTreeVersionsKey == 1) // Filter our tree version
    .filter(|skill| skill.PassiveType.contains(&3)) // Filter for node type. 1 = small attrib, 2 = small, 3 = notable, 4 = keystone 
    .collect();

    // [node_id, seed]
    let rng = build_poe_rng([27308, 5797]);
   
    let mut cumulative_weight: u32 = 0;
    let mut selected: Option<&AlternatePassiveSkill> = None;

    for skill in filtered {
        if skill.SpawnWeight == 0 {
            continue;
        }
        let new_weight: u32 = cumulative_weight + skill.SpawnWeight;
        let rand_value = rng.next(new_weight);

        if rand_value <= skill.SpawnWeight {
            selected = Some(skill);
        }
        cumulative_weight = new_weight;
    }

    println!("{:?}", selected.unwrap().Id);   
    

}
