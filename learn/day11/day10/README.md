# Day 10 – Testing, Verification, and Interface-Based Design

## Overview
Day 10 focused on **testing and verification of robotics control logic**
without relying on real hardware.

The emphasis was on writing **verifiable, safety-oriented software**
using interfaces, test doubles (fakes), and clear separation of concerns.
This mirrors how real medical and robotics systems are validated before
deployment.

---

## Key Objectives
- Enable controller testing without hardware
- Decouple logic from hardware using interfaces
- Verify safety behavior through automated tests
- Practice reasoning about correct vs unsafe behavior
- Understand how design choices affect testability

---

## Core Concepts Introduced

### 1. Interfaces and Dependency Inversion
Introduced abstract interfaces:
- `ISensor`
- `IActuator`

The controller depends on **interfaces**, not concrete implementations.

This allows:
- real hardware in production
- fake hardware in tests
- identical controller logic in both cases

---

### 2. Test Doubles (Fakes)
Implemented fake versions of hardware components:

- **FakeSensor**
  - Returns predefined values
  - Allows deterministic testing

- **FakeActuator**
  - Records whether it was commanded
  - Captures last commanded value

These fakes act as **spies/stubs**, enabling behavioral verification.

---

### 3. Controller Verification
The controller was tested to ensure:

- Valid sensor values:
  - Actuator is commanded
  - Correct command value is sent
- Unsafe sensor values:
  - Negative values → no actuator command
  - Values exceeding safety threshold → no actuator command

This verifies that **unsafe conditions never result in motion**.

---

## Test Implementation

A standalone test executable was written using:
- `assert` for validation
- fake hardware implementations
- no external test framework

### Test Cases Covered
1. Normal operation (valid sensor input)
2. Negative sensor input
3. Sensor input exceeding maximum threshold

Program exits silently if all tests pass.

---

## Files in This Folder

```text
day10/
├── ISensor.h
├── IActuator.h
├── FakeSensor.h
├── FakeActuator.h
├── Controller.h
├── Controller.cpp
├── Logger.h
├── Logger.cpp
└── test_controller.cpp

Real hardware implementations reused from earlier days.