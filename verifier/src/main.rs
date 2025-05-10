use std::{fs, io};
mod tests;
use tests::{Suite, run_program, compare};


fn main() -> io::Result<()> {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 3 {
        eprintln!("Usage: {} <program_path> <suite.toml>", args[0]);
        std::process::exit(1);
    }
    let exe = &args[1];
    let suite_path = &args[2];

    let suite_toml = fs::read_to_string(suite_path)
        .expect("Failed to read suite file");
    let suite: Suite = toml::from_str(&suite_toml)
        .expect("Invalid TOML in suite file");

    let mut all_ok = true;
    for (i, test) in suite.test.iter().enumerate() {
        let actual = run_program(exe, &test.input)
            .expect("Error running student program");
        let ok = compare(&actual, test);
        if ok {
            println!("Test {}: ✅ OK", i + 1);
        } else {
            all_ok = false;
            println!("Test {}: ❌ FAIL", i + 1);
            if let Some(exp) = &test.expected {
                println!("  → Expected:\n{}", exp);
            }
            println!("  → Actual:\n{}", actual);
        }
    }

    if !all_ok {
        std::process::exit(1);
    }
    Ok(())
}

