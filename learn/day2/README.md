# Day 2 – Constructors, Enums, and Safe Object Design in C++

Day 2 focused on learning how to design **safe, well-constructed C++ objects**
using modern C++ practices. These concepts are fundamental to building
reliable, safety-critical robotics software such as surgical robotic systems.

The emphasis was not just on syntax, but on **design intent, correctness,
and preventing invalid system states**.

---

## 🎯 Topics Covered

- Constructors and object creation
- Member initializer lists
- `explicit` constructors and why they matter
- `enum class` for strongly-typed states and modes
- Exception handling (`std::invalid_argument`, `std::logic_error`)
- Defensive programming
- Const-correctness at the object level

---

## 📄 Files in This Folder

```text
day2/
├── calculator.cpp          # Basic calculator with one operation
├── robot_config.cpp          # Safe configuration object with validation
├── motor_controller.cpp      # Motor controller with enforced invariants
├── calculator_refactor.cpp   # Refactored calculator using modern C++ design
└── README.md                 # This file
