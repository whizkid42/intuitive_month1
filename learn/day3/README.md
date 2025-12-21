# Day 3 – Supervisory State Machines in C++

## Overview
Day 3 focused on designing and implementing **supervisory state machines**
using modern C++. The goal was to understand how robotic systems manage
behavior, enforce safety, and prevent illegal operations.

The implementations progress from simple state-based transitions to
event-driven, table-driven, payload-aware, and time-aware (watchdog)
state machines. This mirrors how real robotic and medical systems evolve
from basic control logic to safety-critical supervisory software.

---

## Learning Objectives
- Understand the difference between states and events
- Prevent illegal state transitions
- Centralize decision-making inside a controller
- Design event-driven architectures
- Handle faults with severity-based logic
- Introduce timeouts and watchdog concepts

---

## Files in This Folder

```text
day3/
├── SMV1_practice1.cpp        # Practice set for basic state transitions
├── SMV1_practice2.cpp        # Improved error handling and diagnostics
├── state_machine_v1.cpp     # Direct state-to-state transitions
├── state_machine_v2.cpp     # Event-driven state machine
├── state_machine_v3.cpp     # Table-driven state machine
├── state_machine_v4.cpp     # Payload-based events (fault severity)
├── state_machine_v5.cpp     # Timeouts and watchdog logic

