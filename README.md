# push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations.

## Description

`push_swap` sorts a list of integers using two stacks (A and B) and outputs the minimum sequence of operations required. The program uses an adaptive chunking algorithm that adjusts its strategy based on input size.

### Available Operations

- `sa` / `sb` / `ss`: Swap first 2 elements of stack A / B / both
- `pa` / `pb`: Push top element from B to A / A to B
- `ra` / `rb` / `rr`: Rotate stack up (first element becomes last)
- `rra` / `rrb` / `rrr`: Reverse rotate stack down (last element becomes first)

## Algorithm

The implementation uses an adaptive approach:

- **2-3 numbers**: Hardcoded optimal solutions
- **4-39 numbers**: Selective sorting (pushes smallest values to B, then back to A)
- **40-199 numbers**: Chunking strategy with 18 divisions
- **200+ numbers**: Chunking strategy with 45 divisions

The chunking algorithm divides numbers into groups by rank, pushes them to stack B in order, then pushes back the largest values first.

## Build & Run

```bash
# Compile
make

# Run with numbers as arguments
./push_swap 4 2 1 3

# Count operations
./push_swap 4 67 3 87 23 | wc -l

# Verify instructions are correct with checker
./push_swap 4 2 1 3 | ./checker_MAC 4 2 1 3
# Should output "OK" if sorting is correct, "KO" if not
```

## Project Structure

```
.
├── main.c              # Entry point and chunking algorithm
├── check_input.c       # Input validation and error handling
├── init_lst.c          # Stack initialization and rank assignment
├── instructions.c      # Stack operations (push, swap, rotate, reverse rotate)
├── sort_on_b.c         # Small stack sorting algorithm
├── utils.c             # Utility functions
├── push_swap.h         # Header file with structs and prototypes
├── libft/              # Custom C library
├── algorithms/         # Experimental implementations (archived)
├── checker_MAC         # 42 validator for macOS (verifies sorting correctness)
├── test_inputs.sh      # Input validation tests
└── benchmark.sh        # Performance benchmarking
```

## Testing

### Input Validation Tests
```bash
# Run input validation tests
bash test_inputs.sh
```

### Verify Correctness with Checker
The `checker_MAC` binary validates that push_swap generates correct sorting instructions:

```bash
# Test a specific case
./push_swap 3 2 1 0 | ./checker_MAC 3 2 1 0
# Output: "OK" (correct) or "KO" (incorrect) or "Error" (invalid input)
```

### Performance Benchmarks
```bash
# Run benchmark suite
bash benchmark.sh
```

**Note**: `checker_MAC` is for macOS. Linux users can download `checker_linux` from the 42 intranet.

## Requirements

- **Compiler**: GCC or Clang
- **Build system**: Make
- **OS**: Linux or macOS

## Notes

This project was completed as part of the 42 School curriculum. Alternative algorithm implementations explored during development are preserved in the `/algorithms/` directory.
