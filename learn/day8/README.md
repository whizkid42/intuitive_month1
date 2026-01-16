# Day 8 – Modern C++ Memory Management and RAII in Robotics

## Overview
Day 8 focused on mastering **modern C++ memory management** using RAII
(Resource Acquisition Is Initialization) and applying it to a realistic
robotics module.

The goal was to eliminate unsafe memory patterns (`new` / `delete`) and
replace them with **clear ownership, safe lifetimes, and explicit design**,
as expected in production-quality robotics and medical device software.

---

## Topics Covered

### 1. RAII (Resource Acquisition Is Initialization)
- Understanding why raw `new` / `delete` are dangerous
- Automatic resource cleanup through object lifetimes
- Exception-safe memory management
- Clear ownership semantics

Key principle:
> If an object owns a resource, the resource must be released automatically
> when the object is destroyed.

---

### 2. `std::unique_ptr` and Ownership
- Single-owner heap allocation
- Automatic deletion when owner goes out of scope
- No copying, only explicit ownership transfer
- Clear distinction between **owning** and **borrowing**

Rules applied:
- Own → `std::unique_ptr<T>`
- Borrow → `T&` or `const T&`
- Avoid raw pointers for ownership

---

## Exercise 8.2 – Refactoring Raw Pointers to RAII

### Problem
Refactor legacy-style code using raw pointers and manual `delete` into
modern C++ using RAII.

### Solution
- Replaced raw pointer with `std::unique_ptr`
- Acquired resource in the constructor
- Removed manual destructor logic
- Made ownership explicit and safe

This exercise reinforced correct heap ownership patterns.

---

## Robotics Module – RAII Applied

### Architecture
```text
System
 ├── owns Sensor      (std::unique_ptr)
 ├── owns Actuator    (std::unique_ptr)
 └── owns Controller  (by value)
         ├── borrows Sensor
         └── borrows Actuator
