# push_swap

## Project Overview

**push_swap** is an algorithmic and technical challenge aimed at efficiently sorting a stack of integers using a constrained set of stack operations. The heart of this project is the combination of smart sorting strategies and a custom data structure—a **doubly circular linked list (dclst)**—engineered for flexibility and optimal stack manipulation.

You must sort provided integers placed initially in stack `a` and make stack `a` sorted, using stack `b` only as a helper, and emitting the shortest possible series of specific stack operations on standard output.

## Features

- **Stack operations:**
All required and permitted stack manipulations per 42 subject—swap, push, rotate, and reverse rotate (and their compound versions).
- **Robust input validation:**
Verification of valid integer input, uniqueness, and handling of errors.
- **Optimized sorting strategy:**
Specialized logic for small sizes, and a cost-driven move selection approach for larger stacks.
- **Custom doubly circular linked list (dclst) implementation** for stacks.
- **Bonus checker program:**
Reads operations, validates final stack state, and simulates all operations silently.


## Why and How: The dclst (Doubly Circular Linked List)

### **Motivation: Why a dclst?**

Sorting with push_swap requires constant and efficient access/modification at both the top and bottom of stacks as well as efficient rotation and reverse-rotation operations. Naive approaches (arrays or singly linked lists) present trade-offs:

- **Arrays:**
Fast random access, but rotation and push/pop require shifting elements (inefficient).
- **Singly linked lists:**
Easy stack top modifications, but finding or rotating to the end is expensive (O(n)).

A **doubly circular linked list**—where each node points to both the next and previous elements, and the tail loops back to the head—offers several unique advantages for push_swap:

- **O(1) access to both ends:** Quickly access or modify both the top and bottom nodes.
- **O(1) rotation:** `rotate` and `reverse rotate` become extremely efficient as they are simple pointer updates (no traversal needed).
- **No NULL pointers:** The circular nature eliminates edge-case handling (no stack "end"); even empty stacks have a predictable, single-entry representation if desired.
- **Simpler code for compound actions:** Simultaneous/synchronized operations (`ss`, `rr`, `rrr`) are cleaner to implement.


### **dclst Structure in Practice**

The stack nodes (`t_stack` or similar) are structured as:

```c
typedef struct s_stack {
    int             value;
    struct s_stack *next;
    struct s_stack *prev;
    // Optionally: metadata for sorting, cost, position, etc.
} t_stack;
```

- **Circularity**: The `next` pointer in the last node points back to the first node, and `prev` of the first node links to the last—forming a closed loop.
- **Doubly linked**: Each node has both `next` and `prev`, enabling bi-directional iteration.

### **Usage in the Project**

- **Push/Pop Operations:**
Inserting and removing the top element only requires a handful of pointer realignments—no memory copy or list traversal.
- **Rotate (`ra`/`rb`) and Reverse Rotate (`rra`/`rrb`):**
Rotating stacks is achieved by simply updating the reference to the stack “head.” No need to traverse or rebuild the list.
- **Efficient Target Calculation:**
For optimal moves, elements must find their "target" positions. With dclst, scanning neighbors in both directions is direct and fast.
- **Bonus Checker Operations:**
All possible operations for both stacks (`a` and `b`) are easily applied and reversed.


### **Edge Handling and Robustness**

- **Empty and single-node cases**:
Operations gracefully reduce to no-ops or simple pointer adjustments, since traversal never falls off a NULL terminator.
- **No memory fragmentation**:
All modifications happen in place with no shifting or reallocating, supporting high performance with large lists.


## Compilation

```bash
make            # Build all (push_swap and checker)
make bonus      # Build only checker (bonus)
make clean      # Remove object files
make fclean     # Full clean (executables and objects)
make re         # Full rebuild
```


## Usage

### push_swap

```bash
./push_swap [list of integers]
```

- Outputs ordered stack operations (one per line).
- Handles error detection (duplicates, invalid input) and exits silently for empty input.


### checker (bonus)

```bash
./checker [list of integers]
```

- Reads instructions from standard input, simulates their effect on stacks a and b, and prints `OK` or `KO`.


## Architecture \& Program Flow

1. **Input Parsing \& Validation**
    - Input arguments are validated and loaded into stack a using the dclst.
    - Error messages are precise and consistent (“Error” to `stderr`).
2. **Sorting Algorithm**
    - For small input:
        - Use optimal sorting routines (e.g., direct swaps/rotates).
    - For larger input:
        - Move the “cheapest” elements between stacks using a cost model.
        - Each element tracks its move/target position via dclst iteration.
        - Reintegrate elements from stack b back into stack a for the final sorted state.
3. **Operations**
    - Implemented via efficient pointer manipulation in dclst:
        - Swap, push, rotate, reverse rotate.
        - All compound and silent variants for checker.
    - The circular/double nature enables O(1) complexity for almost every operation.
4. **Memory Management**
    - All allocations and frees for dclst nodes handled with care—no leaks.
    - On exit or error, all structures are cleaned up.

## Instruction Reference

| Instruction | Effect |
| :-- | :-- |
| sa | Swap first two elements of stack a |
| sb | Swap first two elements of stack b |
| ss | sa and sb simultaneously |
| pa | Push top of b to a |
| pb | Push top of a to b |
| ra | Rotate stack a (first element becomes last) |
| rb | Rotate stack b |
| rr | ra and rb simultaneously |
| rra | Reverse rotate a (last element becomes first) |
| rrb | Reverse rotate b |
| rrr | rra and rrb simultaneously |

## Bonus: Checker Program

- Simulates stack operations from stdin using dclst logic.
- At completion, validates sorted state in O(n) using dclst traversal.
- Uses internal “silent” operation variants for state changes.


## Error Handling

- Reports invalid input, duplicate values, or out-of-range integers with `Error`.
- Ensures zero memory leaks and full dclst cleanup on exit.
- All possible edge cases robustly handled, especially due to circular/double nature—no NULL dereferences.


## Credits

- Author: [Nicolas Fromont, alias nifromon]
- 42 Network, push_swap project

