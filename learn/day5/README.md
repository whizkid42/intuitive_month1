
# Day 5 – C++ Project Structure and Modular Design

## Overview
Day 5 introduced **real-world C++ code organization**, focusing on how robotics
and embedded software projects are structured at scale.

The goal was to understand:
- separation of interface and implementation
- clean class design
- ownership and responsibility boundaries

This mirrors how large robotics systems (e.g., medical robots) are developed.

---

## Topics Covered

### 1. Header and Source Files
- Purpose of `.h` vs `.cpp`
- Interface vs implementation
- Reducing coupling and improving compile times

### 2. Class Design
- Public APIs vs private data
- Constructors and initialization
- Const-correct interfaces

### 3. Ownership and Dependencies
- Passing objects by reference
- Avoiding unnecessary ownership
- Clear responsibility separation

---

## Files in This Folder

```text
day5/
├── Sensor.h
├── Sensor.cpp
├── Controller.h
├── Controller.cpp
└── main.cpp
