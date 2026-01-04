# Algorithm Experiments

This directory contains alternative sorting algorithms explored during development.
These implementations are not used in the production binary but are preserved to show the iterative development process.

## Implementations

- **chunking.c**: Cost-optimized chunk selection with min_b tracking
- **cost_based_insertion.c**: Full cost analysis for every possible insertion point (Turkish algorithm variant)
- **half_sort_on_b.c**: Strategy that sorts the smallest half to stack B, then processes the remainder
- **small_half_to_b.c**: Rotate-based sorting approach
- **sort_on_b_prog.c**: Progressive sorting variant

## Notes

These files are kept for educational purposes and to demonstrate algorithmic exploration.
The active implementation used in the final binary is in `main.c` in the project root.
