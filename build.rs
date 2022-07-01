extern crate cc;

fn main() {
    cc::Build::new()
        .file("poe-rng/poe-rng.c")
        .compile("poerng");
}