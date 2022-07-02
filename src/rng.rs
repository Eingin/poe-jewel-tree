#[link(name = "poerng")]
extern {
    fn tintmt_init(state: *const u32, seed: *const u32) -> i32;
    fn tintmt_next(state: *const u32, max: i32) -> i32;
    fn tintmt_next_range(state: *const u32, min: i32, max: i32) -> i32;
}

pub struct PoeRng {
    pub state: [u32; 5],
    seed: [u32; 2]
}

pub trait RNG {
    fn next(&self, max: i32) -> i32;
    fn next_range(&self, min: i32, max: i32) -> i32;
}

impl RNG for PoeRng {
    fn next(&self, max: i32) -> i32 {
        unsafe {
             return tintmt_next(&self.state[0], max);
        }
    }

    fn next_range(&self, min: i32, max: i32) -> i32 {
        unsafe {
            return tintmt_next_range(&self.state[0], min, max);
       }
        
    }
}

pub fn build_poe_rng(seed: [u32; 2]) -> PoeRng {
    let rng = PoeRng {
        state:  [0; 5],
        seed: seed,
    };
    unsafe {
        tintmt_init(&rng.state[0], &rng.seed[0]);
    }
    return rng;
}
