*This project has been created as part of the 42 curriculum by ekart.*

# Push_swap

## Description

Push_swap is an algorithmic project focused on sorting data efficiently. The goal is to sort a stack of integers in ascending order using a limited set of stack operations, while minimizing the total number of moves.

The project challenges you to:
- Implement efficient sorting algorithms
- Understand algorithmic complexity
- Optimize for different input sizes
- Handle edge cases and error management

The program must handle stacks of varying sizes (from 2 to 500+ integers) and meet strict performance benchmarks.

## Instructions

### Compilation

```bash
make
```

This will compile the `push_swap` program and the libft library.

### Cleaning

```bash
make clean   # Remove object files
make fclean  # Remove object files and executables
make re      # Recompile everything from scratch
```

### Usage

```bash
./push_swap [list of integers]
```

**Examples:**

```bash
# Sort 3 numbers
./push_swap 2 1 3

# Sort 5 numbers
./push_swap 5 4 3 2 1

# Using quotes (space-separated in one argument)
./push_swap "4 67 3 87 23"

# Mix of both formats
./push_swap 1 "5 3" 2
```

### Testing with Checker

```bash
# Python checker (included)
./push_swap 3 2 1 | python3 checker.py 3 2 1

# Should output: OK (if sorted correctly) or KO (if not sorted)
```

### Performance Benchmarks

According to the subject requirements:

| Elements | Excellent (100%) | Good (80%) |
|----------|------------------|------------|
| 3 numbers | ≤ 3 moves | - |
| 5 numbers | ≤ 12 moves | - |
| 100 numbers | < 700 moves | < 1100 moves |
| 500 numbers | < 5500 moves | < 8500 moves |

**Current Performance:**
- 3 numbers: ≤ 3 moves ✓
- 5 numbers: ~8-9 moves ✓
- 100 numbers: ~1084 moves (optimization needed)
- 500 numbers: ~6784 moves (optimization needed)

## Algorithm

The project implements multiple sorting strategies:

### Small Stacks (2-5 elements)
- **2 elements:** Simple swap if needed
- **3 elements:** Hardcoded optimal solution (max 3 moves)
- **4-5 elements:** Find minimum, push to stack B, sort remaining, push back

### Large Stacks (6+ elements)
- **Radix Sort:** Binary-based sorting algorithm
  - Assigns index to each value
  - Sorts by bit position (LSB to MSB)
  - Time complexity: O(n × log n)
  - Efficient for larger datasets

## Project Structure

```
42-push_swap/
├── 42-Libft/           # Custom C library
├── inc/
│   └── push_swap.h     # Main header file
├── src/
│   ├── main.c          # Entry point
│   ├── parse.c         # Argument parsing
│   ├── parse_utils.c   # Validation functions
│   ├── stack.c         # Stack initialization and node creation
│   ├── stack_ops.c     # Stack operations (rotate, push_bottom, clear)
│   ├── stack_swap.c    # Swap operation
│   ├── stack_utils.c   # Utility functions (is_sorted, print_stack)
│   ├── ops_swap.c      # sa, sb, ss operations
│   ├── ops_push.c      # pa, pb operations
│   ├── ops_rotate.c    # ra, rb, rr, rra, rrb operations
│   ├── ops_rrotate.c   # rrr operation
│   ├── sort_small.c    # Sorting for 2-5 elements
│   └── sort_big.c      # Radix sort for larger inputs
├── checker.py          # Python checker for testing
└── Makefile
```

## Available Operations

- `sa` - Swap first 2 elements of stack A
- `sb` - Swap first 2 elements of stack B
- `ss` - sa and sb simultaneously
- `pa` - Push top element from B to A
- `pb` - Push top element from A to B
- `ra` - Rotate stack A up (first → last)
- `rb` - Rotate stack B up (first → last)
- `rr` - ra and rb simultaneously
- `rra` - Reverse rotate stack A (last → first)
- `rrb` - Reverse rotate stack B (last → first)
- `rrr` - rra and rrb simultaneously

## Error Handling

The program outputs `Error\n` to stderr and exits for:
- Non-numeric arguments
- Numbers outside INT_MIN to INT_MAX range (-2147483648 to 2147483647)
- Duplicate numbers
- Invalid input format
- Memory allocation failures

## Resources

### Algorithm References
- [Sorting Algorithms - GeeksforGeeks](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Data Structure - Programiz](https://www.programiz.com/dsa/stack)
- [Push_swap - 42 Docs](https://harm-smits.github.io/42docs/projects/push_swap)

### Technical Documentation
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html)
- [C Memory Management](https://en.cppreference.com/w/c/memory)
- [42 Norm](https://github.com/42School/norminette)

### AI Usage

**AI tools were used for the following purposes:**

1. **Code Review & Debugging:**
   - Identified missing NULL check in parse.c after malloc
   - Helped debug edge cases in argument parsing
   - Suggested improvements for error handling

2. **Algorithm Understanding:**
   - Clarified radix sort bit manipulation concepts
   - Explained complexity trade-offs between different algorithms
   - Provided examples of sorting optimization strategies

3. **Testing:**
   - Generated test case ideas (edge cases, large datasets)
   - Helped create Python checker script for validation
   - Suggested benchmark testing methodology

4. **Documentation:**
   - Assisted in writing this README
   - Helped explain complex algorithmic concepts

**Note:** All core algorithm implementation, stack operations, and sorting logic were developed manually after understanding the concepts. AI was used as a learning aid and debugging assistant, not for code generation.

## Author

**ekart** - 42 Istanbul

## License

This is a 42 school project. Free to use for educational purposes.