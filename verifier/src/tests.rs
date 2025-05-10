use regex::Regex;
use serde::Deserialize;
use std::io::{self, Write};
use std::process::{Command, Stdio};

#[derive(Deserialize)]
pub struct Test {
    pub input: String,
    pub expected: Option<String>,
    pub numeric_tolerance: Option<f64>,
}

#[derive(Deserialize)]
pub struct Suite {
    pub test: Vec<Test>,
}

pub fn run_program(exe_path: &str, input: &str) -> io::Result<String> {
    let mut child = Command::new(exe_path)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .spawn()?;

    child.stdin.as_mut().unwrap().write_all(input.as_bytes())?;
    let output = child.wait_with_output()?;
    Ok(String::from_utf8_lossy(&output.stdout).to_string())
}

fn extract_results(output: &str) -> Vec<String> {
    output
        .lines()
        .filter_map(|line| {
            let trimmed = line.trim_start();
            if trimmed.starts_with("Nome:") {
                Some(trimmed.to_string())
            } else {
                None
            }
        })
        .collect()
}

pub fn compare(actual: &str, test: &Test) -> bool {
    let actual_lines = extract_results(actual);

    if let Some(tol) = test.numeric_tolerance {
        let re_num = Regex::new(r"-?\d+(?:\.\d+)?").unwrap();
        let expected_lines = extract_results(test.expected.as_ref().unwrap());

        // Collect numerical values from each line
        let nums_act: Vec<f64> = actual_lines
            .iter()
            .flat_map(|line| {
                re_num
                    .find_iter(line)
                    .filter_map(|m| m.as_str().parse().ok())
            })
            .collect();
        let nums_exp: Vec<f64> = expected_lines
            .iter()
            .flat_map(|line| {
                re_num
                    .find_iter(line)
                    .filter_map(|m| m.as_str().parse().ok())
            })
            .collect();

        if nums_act.len() != nums_exp.len() {
            return false;
        }
        nums_act
            .iter()
            .zip(nums_exp.iter())
            .all(|(a, e)| (a - e).abs() <= tol)
    } else if let Some(_) = &test.expected {
        let expected_lines = extract_results(test.expected.as_ref().unwrap());
        actual_lines == expected_lines
    } else {
        false
    }
}

