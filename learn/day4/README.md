# Day 4 – Core C++ Foundations for Robotics

## Overview
Day 4 focused on strengthening **core C++ fundamentals** that are essential for
writing safe, readable, and review-ready robotics software.

The emphasis was on:
- const-correctness
- safe parameter passing
- modern containers
- clean iteration patterns

These concepts are heavily used in real-world robotics and embedded systems,
especially in safety-critical environments.

---

## Topics Covered

### 1. Const Correctness
- `const` variables
- `const` references
- `const` member functions
- Preventing unintended modification at compile time

### 2. References vs Pointers
- When to prefer references
- Why `const T&` is the default choice
- Avoiding nullability and ownership confusion

### 3. Safe Function Interfaces
- Passing objects by `const T&`
- Avoiding unnecessary copies
- Making intent explicit in APIs

### 4. Modern Containers
- Introduction to `std::vector`
- Dynamic resizing with `push_back`
- Range-based for loops for safe iteration

---

## Files in This Folder

```text
day4/
├── loops_exercise.cpp     # Practicing loop with exercise
└── vector_basics.cpp      # std::vector and range-based loop example
