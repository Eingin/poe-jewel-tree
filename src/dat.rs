use std::{fs::File, collections::HashMap};
use std::io::Read;
use serde::{Deserialize, Serialize, de};

#[derive(Serialize, Deserialize, Debug)]
pub struct AlternateTreeVersion {
    pub _rid: u32,
    #[serde(alias = "Id")]
    pub id: String,
    #[serde(alias = "ReplaceChance")]
    pub replace_chance: i32,
    #[serde(alias = "ReplaceAttributeNodes")]
    pub replace_attribute_nodes: bool,
    #[serde(alias = "ReplaceSmallNodes")]
    pub replace_small_nodes: bool
}

#[derive(Serialize, Deserialize, Debug)]
pub struct AlternatePassiveSkill {
    pub _rid: u32,
    #[serde(alias = "Id")]
    pub id: String,
    #[serde(alias = "AlternateTreeVersionsKey")]
    pub alternate_tree_versions_key: u32,
    #[serde(alias = "Name")]
    pub name: String,
    #[serde(alias = "SpawnWeight")]
    pub spawn_weight: i32,
    #[serde(alias = "PassiveType")]
    pub passive_type: Vec<i32>,
    #[serde(alias = "StatsKeys")]
    pub stats_keys:  Vec<u32>,
    #[serde(alias = "Stat1Min")]
    pub stat1_min: i32,
    #[serde(alias = "Stat1Max")]
    pub stat1_max: i32,
    #[serde(alias = "Stat2Min")]
    pub stat2_min: i32,
    #[serde(alias = "Stat2Max")]
    pub stat2_max: i32,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct AlternatePassiveAddition {
    pub _rid: u32,
    #[serde(alias = "Id")]
    pub id: String,
    #[serde(alias = "AlternateTreeVersionsKey")]
    pub alternate_tree_versions_key: u32,
    #[serde(alias = "SpawnWeight")]
    pub spawn_weight: i32,
    #[serde(alias = "PassiveType")]
    pub passive_type: Vec<i32>,
    #[serde(alias = "StatsKeys")]
    pub stats_keys:  Vec<u32>,
    #[serde(alias = "Stat1Min")]
    pub stat1_min: i32,
    #[serde(alias = "Stat1Max")]
    pub stat1_max: i32,
}

#[derive(Serialize, Deserialize, Debug)]
pub struct SkillTreeNode {
    #[serde(default)]
    pub skill: i32,
    #[serde(default)]
    pub name: String,
    #[serde(alias = "isNotable", default)]
    pub is_notable: bool,
    #[serde(alias = "isKeystone", default)]
    pub is_keystone: bool,
    #[serde(default)]
    pub stats: Vec<String>,
    #[serde(alias = "in", default)]
    pub in_nodes: Vec<String>,
    #[serde(alias = "out", default)]
    pub out_nodes: Vec<String>,
    #[serde(alias = "grantedDexterity", default)]
    pub granted_dexterity: i32,
    #[serde(alias = "grantedStrength", default)]
    pub granted_strength: i32,
    #[serde(alias = "grantedIntelligence", default)]
    pub granted_intelligence: i32,
}

impl SkillTreeNode {
    pub fn get_pasive_type(&self) -> i32 {
        if self.is_keystone { return 4 }
        if self.is_notable { return 3 }
        if self.granted_dexterity > 0 ||  self.granted_strength > 0 ||  self.granted_intelligence > 0 { return 1 }
        return 2
    }
}

#[derive(Serialize, Deserialize, Debug)]
pub struct SkillTree {
    pub tree: String,
    pub nodes: HashMap<String, SkillTreeNode>
}

pub fn load_json<T>(file_name: &str) -> T
where
    T: de::DeserializeOwned {
    let mut file = File::open(file_name).unwrap();
    let mut data = String::new();
    file.read_to_string(&mut data).unwrap();
    return serde_json::from_str(&data).unwrap();
}