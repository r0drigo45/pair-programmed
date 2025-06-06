﻿# Paired Programmed

**Paired Programmed** is a collaborative coding exercise project between two developers solving the same problems in different programming languages — one in **Python**, the other in **C**. Solutions are validated using a shared **Rust test runner**.

---

## 🚀 Purpose

- Help a beginner learn programming through real problem-solving in Python.
- Encourage comparison between dynamic (Python) and low-level (C) solutions.
- Use Rust as a fast, type-safe foundation for testing both implementations.
- Enforce good development practices: branches, pull requests, and code reviews.

---

## 🗂️ Project Structure

```
paired-programmed/
├── exercises/
│ ├── exercise_01/
│ │ ├── problem.md # Problem description
│ │ ├── solution.py # Python solution
│ │ ├── solution.c # C solution
│ │ └── test.rs # Rust-based test
│ └── ...
├── test-runner/ # Rust test runner crate
│ ├── src/
│ └── Cargo.toml
└── README.md
```
---

## 🛠️ Workflow

### 1. Branching

Each person works on a **separate branch**:
- `python-dev`: for the Python solutions
- `c-dev`: for the C solutions

Create feature branches off your language-specific branch when working on a new exercise:
```sh
git checkout -b python/exercise-01
```

### 2. Pull Requests & Reviews
Push your branch.

Open a Pull Request to main.

Your partner must review the code before merging.

Only merge after approval and green test results.

### 3. Running Tests
The Rust test runner is used to validate both implementations.

Requirements
- Rust
-Python 3
- GCC (or compatible C compiler)

```sh
cd test-runner
cargo test
```

The test runner executes both implementations (via subprocess or compiled binaries) and compares their outputs.

### 🧩 Adding a New Exercise
Create a new folder under exercises/:

`mkdir exercises/exercise_02`

Add:

`problem.md`: problem statement

`solution.py`: your Python solution

`solution.c`: your C solution

`test.rs`: Rust tests for validating output

Follow the branching + PR process to merge your work.


### 📜 License
MIT License. Use it, modify it, break it — just don’t blame us.

### 🙅 Contributions
Not open to outside contributions right now. Fork it if you're doing something similar.

