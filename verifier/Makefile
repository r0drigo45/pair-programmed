# Top-level Makefile inside the `verifier/` directory

# C solution directory for exercise 01 (one level up)
C01_DIR      := ../solutions/c/01
# Path to the compiled C binary (named “app” by that Makefile)
C01_EXE      := $(C01_DIR)/app

# Rust verifier directory is the current dir
VERIFIER_DIR := .
# Path to the compiled verifier binary
VERIFIER     := $(VERIFIER_DIR)/target/debug/verifier

# Test suite for ex01 inside the verifier folder
SUITE        := $(VERIFIER_DIR)/test_suites/media_alunos.toml

.PHONY: all build-c01 build-verifier test-c01 clean

# Default: run tests for ex01
all: test-c01

# Build the C solution for ex01
build-c01:
	$(MAKE) -C $(C01_DIR)

# Build the Rust verifier
build-verifier:
	cargo build

# Run the verifier against the C solution for ex01
test-c01: build-c01 build-verifier
	@echo "→ Testing C solution for ex01:"
	$(VERIFIER) $(C01_EXE) $(SUITE)

# Clean C and Rust build artifacts
clean:
	$(MAKE) -C $(C01_DIR) clean
	cargo clean

