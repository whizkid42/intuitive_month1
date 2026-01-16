# Day 6 – Robotics Modules, Memory Lifetimes, and Build Systems

## Overview
Day 6 focused on understanding how **real robotics software is structured,
built, and kept safe at runtime**.

The day was split into three logical parts:
1. Building a light robotics-style module (Sensor–Controller–Actuator)
2. Understanding memory ownership and object lifetimes
3. Learning how C++ code is compiled and linked using build tools

This day connects C++ language features with **practical system-level thinking**.

---

## Part C – Light Robotics Module Design

### Goal
To practice clean, realistic robotics architecture **without state machines**.

### Architecture
```text
Sensor  →  Controller  →  Actuator
