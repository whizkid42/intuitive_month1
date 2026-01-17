# Day 11 – Failure Injection, Fault Handling, and Fail-Safe Robotics Control

## Overview
Day 11 focused on designing and verifying **fail-safe behavior** in a robotics
control system through **explicit failure modeling and failure injection**.

In medical and safety-critical robotics, systems must behave safely not only
during normal operation, but also when sensors fail, return invalid data, or
become unreliable. This day demonstrates how such failures are detected,
handled, and proven safe through code and tests.

---

## Key Objectives
- Model sensor health explicitly
- Detect and respond to component failures
- Inhibit unsafe actuator commands under fault conditions
- Verify fail-safe behavior using failure injection tests
- Strengthen the safety argument of the control system

---

## Failure Modeling

### Sensor Health Representation
A sensor health model was introduced using an explicit status enum:

- `OK` – sensor operating normally
- `FAILED` – sensor failure detected
- `STALE` – sensor data no longer reliable

Sensor interfaces now provide both:
- sensor data
- sensor health status

This prevents blind trust in raw sensor values.

---

## Interface Design Changes

The sensor interface was extended to report health:

- `read()` provides the measured value
- `status()` reports the validity of that value

Controllers depend on **both value and status** before making decisions.

---

## Fail-Safe Controller Logic

The controller enforces the following safety rules:

1. If sensor status is not `OK`, motion is immediately inhibited
2. If sensor values fall outside the safe operating range, motion is inhibited
3. Actuators are commanded **only** when:
   - sensor status is valid
   - sensor values are within verified safety limits

All unsafe conditions result in:
- clear error logging
- early return
- zero actuator motion

This ensures the system fails safely.

---

## Failure Injection and Verification

Failure scenarios were injected using fake sensor implementations that
simulate:

- complete sensor failure
- stale or unreliable data

Automated tests verify that:
- no actuator commands occur during failures
- controller behavior is deterministic and safe
- unsafe conditions are handled predictably

These tests serve as **evidence of safety behavior**, not just correctness.

---

## Files in This Folder

```text
day11/
├── SensorStatus.h
├── ISensor.h
├── FakeSensor.h
├── Controller.h
├── Controller.cpp
├── Logger.h
├── Logger.cpp
└── test_controller.cpp

Other system components reused from previous days.