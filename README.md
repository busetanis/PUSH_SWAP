# Push_Swap

> *"Because Swap_Push isn't quite as natural."*

## About the Project
**Push_Swap** is a project that aims to sort a sequence of integers using a very limited set of commands (only two stacks: Stack A and Stack B) with **the fewest moves possible**. This project is not only about implementing a sorting algorithm; it also requires complete mastery of time complexity, memory management, and data structures (Linked Lists).

---

## Description

"Algorithm Logic and Mathematical Models"

The main goal of the Push_Swap project is not simply sorting numbers, but minimizing the costs of data transfers (`pa`, `pb`) and rotations (`ra`, `rb`) between Stack A and Stack B. Our algorithm operates through a **Dispatcher** structure that dynamically selects the most appropriate strategy according to the input size (`size`) and disorder ratio (`disorder`).

### 1. Target-Oriented Indexing (Simple Sort)
Instead of dealing with the absolute values of numbers, the `index_stack` function assigns every element (from 0 to N-1) an index according to its sorted order. For small datasets, the system searches for indices 0, 1, 2... in sequence, calculates the shortest path depending on whether the target is closer to the top or bottom of the stack, and pushes it to Stack B. Since the numbers are already pushed into Stack B in sorted order (smallest to largest), they can be restored to Stack A without any additional operations.

### 2. Dynamic Windows with Linear Interpolation (Medium Chunk Sort)
In classical Butterfly algorithms, the chunk size is usually hardcoded as magic numbers such as 15 or 30. For medium-sized datasets, we made this value completely dynamic using a **Linear Interpolation Equation**.

**Optimization Problem (Trade-off):**
* If the window is too narrow: excessive searching (`ra`) is required in Stack A.
* If the window is too wide: excessive rotations (`rb`) are required in Stack B while retrieving the largest values.

**Mathematical Model:**

chunk_size = (size / 20) + 10

Thanks to C's Integer Division, this formula automatically truncates decimal values and calculates the most suitable chunk width in milliseconds.

### 3. Divide and Conquer (Complex Quick Sort)
If the dataset is very large or completely reverse sorted, the system switches to a **Quick Sort** algorithm with **O(N log N)** time complexity.

* **Pivot Selection:** The stack median is selected as the pivot.
* **Partitioning:** Values smaller than the pivot are pushed to Stack B, while larger values remain in Stack A.
* **Recursion:** This process repeats until only small and easily manageable groups remain.

---

## Why Did We Choose These Algorithms? (Design Decisions)

Push_Swap differs from traditional sorting algorithms because it optimizes **instruction count** rather than CPU execution time.

* **Why Simple Sort? (≤ 5 Elements):** Designed specifically for very small datasets and minimizes unnecessary push operations.
* **Why Medium Chunk Sort? (≤ 500 Elements):** Reduces rotation costs and adapts dynamically to input size.
* **Why Complex Quick Sort? (Large Datasets):** Takes advantage of Divide & Conquer efficiency and median pivot selection.

---

## Team and Task Distribution

### 👩‍💻 Buse (@butanis)
* Parsing & Validation
* Stack Operations
* Complex Quick Sort Design and Integration

### 👨‍💻 Batuhan (@btop)
* Stack Management
* Simple Sort & Medium Chunk Sort
* Benchmarking & Dispatcher

### 🤝 Shared Responsibilities
* Valgrind checks
* Makefile optimization
* Norminette compliance

---

## Installation and Testing

```bash
make
make clean

./push_swap 4 67 3 87 23

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
