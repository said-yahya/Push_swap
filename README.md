*This project has been created as part of the 42 curriculum by edpolat, ysaikhuj.*

# Push_swap

## Description

Push_swap is an algorithmic sorting project where the goal is to sort a list of integers using two stacks (`a` and `b`) and a limited set of operations.

The challenge is not only to sort the numbers correctly, but to do so using the **smallest possible number of operations** in the Push_swap instruction set:

sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

The project focuses on:
- Algorithmic complexity
- Operation cost analysis (measured in Push_swap operations)
- Strategy selection based on input disorder
- Clean memory management and strict C implementation (Norm compliant)

---

## Project Structure

This project implements **four different sorting strategies**, as required:

1. Simple algorithm – O(n²)
2. Medium algorithm – O(n√n)
3. Complex algorithm – O(n log n)
4. Adaptive algorithm – dynamically selects a strategy based on disorder

---

## Implemented Algorithms

### 1 Simple Algorithm – O(n²)

A basic selection-style approach is used:
- The smallest elements are located in stack `a`
- Depending on their position, `ra` or `rra` is used
- Elements are pushed to `b`
- Finally pushed back to `a` in sorted order

This approach is efficient for:
- Small inputs
- Low disorder cases

---

### 2 Medium Algorithm – O(n√n)

Implemented by: **ysaikhuj**

This strategy uses a **chunk-based sorting approach**:
- The input is divided into √n chunks
- Elements are pushed to stack `b` in chunk ranges
- Smart rotations are used to minimize move cost
- Elements are then reassembled in sorted order

This reduces total operations compared to O(n²) strategies for medium-sized inputs.

---

### 3 Complex Algorithm – O(n log n)

Implemented by: **ysaikhuj**

This strategy is based on a **Radix Sort adaptation** in the Push_swap model:

- Numbers are indexed
- Bitwise sorting is applied
- Elements are distributed between stacks based on bit values
- Reassembled efficiently

Radix ensures:
- Predictable O(n log n) operation count
- Strong performance for large inputs (100–500 elements)

---

### 4 Adaptive Algorithm

The adaptive strategy measures the **disorder metric** before sorting.

Disorder is computed as:
mistakes / total_pairs

Based on disorder:

- disorder < 0.2 or size of stack < 5 → O(n²) strategy
- 0.2 ≤ disorder < 0.5 or size of stack < 600 → O(n√n) strategy
- disorder ≥ 0.5 → O(n log n) strategy

This ensures:
- Nearly sorted inputs are handled efficiently
- Fully random inputs use optimal complexity

---
## Benchmark Mode (`--bench`)

The project includes an integrated **performance analysis mode** enabled with:

```bash
./push_swap --bench <numbers>
```

When `--bench` is used:

- Sorting operations are printed to **stdout**
- All benchmark metrics are printed to **stderr**
- The operation stream remains clean and pipe-compatible

This guarantees that the program can still be used with `checker` while collecting performance data independently.

---

### What the Benchmark Displays

After sorting, the following metrics are reported:

#### 1. Disorder (%)

- Computed **before any operation is executed**
- Defined as:

```
disorder = mistakes / total_pairs
```

- Displayed as a percentage with two decimal precision
- Measures how far the initial stack is from being sorted

This value is also used by the adaptive strategy to select the appropriate algorithm.

---

#### 2. Selected Strategy

Displays the name of the strategy used:

- Simple (O(n²))
- Medium (O(n√n))
- Complex (O(n log n))
- Adaptive (auto-selected)

This confirms that runtime strategy selection works correctly.

---

#### 3. Theoretical Complexity Class

The benchmark explicitly states the expected upper bound in the **Push_swap operation model**.

Important:  
Complexity is measured in terms of **number of generated Push_swap operations**, not classical array-based time complexity.

---

#### 4. Total Operation Count

Displays the total number of operations generated.

This is the primary performance metric used during evaluation and benchmarking.

---

#### 5. Per-Operation Breakdown

Displays the count of each instruction type:

- sa, sb, ss  
- pa, pb  
- ra, rb, rr  
- rra, rrb, rrr  

This detailed breakdown helps:

- Identify unnecessary rotations
- Detect inefficient patterns
- Compare strategies under different disorder levels
- Optimize overall move count

---

### Why Benchmark Mode Matters

Benchmark mode was designed to:

- Validate theoretical complexity claims
- Measure real operation costs
- Compare strategies under identical inputs
- Verify correct adaptive selection behavior
- Optimize performance toward excellent thresholds:

For 100 numbers:
- < 700 operations → Excellent

For 500 numbers:
- < 5500 operations → Excellent

It also serves as a development tool for performance tuning and debugging.

## Bonus Part – Checker

As part of the bonus implementation, we developed a custom `checker` program.

The purpose of the checker is to verify whether the sequence of operations generated by `push_swap` correctly sorts the stack.

---

### Compilation

To compile the checker:

```bash
make bonus
```

This generates the executable:

```
checker
```

---

### Usage

The checker takes the initial stack as arguments and reads operations from standard input.

Example:

```bash
./checker 3 2 1 0
```

Then provide operations:

```
rra
pb
sa
rra
pa
```

If the result is correctly sorted and stack `b` is empty:

```
OK
```

Otherwise:

```
KO
```

---

### Error Handling

The checker prints:

```
Error
```

to `stderr` in case of:

- Non-integer arguments
- Integer overflow
- Duplicate values
- Invalid or malformed instructions
- Incorrect parsing input

---

### Implementation Details

The checker:

- Parses and validates all input arguments
- Reuses the same stack structure as `push_swap`
- Reads instructions line by line from `stdin`
- Validates each instruction before execution
- Executes operations safely
- Ensures no memory leaks
- Verifies that:
  - Stack `a` is sorted in ascending order
  - Stack `b` is empty

The bonus implementation strictly follows the subject constraints and is fully compatible with the mandatory part.

---

### Example Integration

`push_swap` can be directly piped into `checker`:

```bash
ARG="4 67 3 87 23" ; ./push_swap $ARG | ./checker $ARG
```

If everything works correctly:

```
OK
```

This confirms both the correctness of the algorithm and the validity of the generated operation stream.


## Contributions

This project was completed as a group project by:

### edpolat
- Core project architecture
- Simple algorithm (O(n²))
- Parsing and error handling
- Stack structure management
- Strategy selection system
- Benchmark mode integration

### ysaikhuj
- Medium algorithm (chunk-based)
- Complex algorithm (radix-based)
- Optimization of rotate / reverse rotate operations
- Performance tuning for operation count

Both contributors understand all implemented algorithms and can explain any part of the codebase.

---

## Compilation

The project is compiled using the provided Makefile.

To compile the main program:

```bash
make
```

This will generate the executable:

```
push_swap
```

---

### Available Makefile Rules

```bash
make            # Compile push_swap
make clean      # Remove object files
make fclean     # Remove object files and executables
make re         # Recompile everything from scratch
make bonus      # Compile the checker program
```
---

## Resources

The following resources were referenced during the development of this project:
- Radix Sort  
  
- Merge Sort  
  https://en.wikipedia.org/wiki/Merge_sort
- Push_swap Overview and Strategy Explanation
  https://www.gibbontech.com/ecole42

## AI Usage

AI tools were used in a limited and responsible manner during this project.

### Scope of Usage

AI assistance was used for:

- Discussing algorithmic complexity classes
- Comparing possible sorting strategies
- Brainstorming optimization ideas
- Reviewing theoretical operation bounds
- Drafting and refining documentation (README)

AI was not used to automatically generate core algorithms that were blindly integrated into the project.

---