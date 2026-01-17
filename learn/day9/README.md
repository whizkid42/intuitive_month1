# Day 9 – Logging, Diagnostics, and Safety-Oriented Control Logic

## Overview
Day 9 focused on introducing **logging, diagnostics, and safety-aware decision
making** into a robotics control module.

In real robotic and medical device systems, failures must never be silent.
This day emphasized how engineers make system behavior **observable, traceable,
and debuggable**, even without a debugger attached.

---

## Key Objectives
- Introduce structured logging with severity levels
- Improve observability of controller behavior
- Distinguish between normal, abnormal, and unsafe conditions
- Prevent unsafe actuator commands through defensive logic
- Practice safety-first control flow patterns

---

## Topics Covered

### 1. Logging Fundamentals
- Why logging is critical in robotics and medical devices
- Difference between `INFO`, `WARN`, and `ERROR` levels
- Logging as part of the safety system, not just debugging output

Implemented a minimal logging utility with:
- log level
- component name
- descriptive message

---

### 2. Diagnostics and Observability
Controllers were instrumented to log:
- sensor readings
- abnormal input conditions
- safety threshold violations

This allows system behavior to be reconstructed after execution.

---

### 3. Safety-Oriented Control Logic
Applied a safety-first structure in the controller:

1. Read input
2. Log observation
3. Validate input against safety bounds
4. Exit early on abnormal or unsafe conditions
5. Command actuators only when input is confirmed safe

This pattern is commonly used in safety-critical robotics software.

---

## Controller Safety Logic

Key behaviors implemented:
- Negative sensor values:
  - Logged as `WARN`
  - Actuator command blocked
- Sensor values exceeding maximum threshold:
  - Logged as `ERROR`
  - Actuator command blocked
- Valid sensor values:
  - Actuator commanded normally

Unsafe conditions never result in actuator motion.

---

## Files Involved

```text
day9/
├── Logger.h
├── Logger.cpp
├── Controller.cpp
├── System.cpp
└── main.cpp

Other module files reused from Day 8.