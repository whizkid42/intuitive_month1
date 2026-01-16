# Day 7 – Debugging, Compilation, and System-Level Reasoning

## Overview
Day 7 focused on building **confidence in understanding and debugging C++ projects**,
rather than writing new code.

The emphasis was on:
- understanding compiler vs linker errors
- reading and interpreting error messages calmly
- reasoning about multi-file builds
- interview-style system thinking

This day strengthened the ability to work effectively in large,
real-world robotics codebases.

---

## Topics Covered

### 1. Compilation vs Linking
- Difference between compiler errors and linker errors
- Why `.cpp` files are compiled and `.h` files are included
- Meaning of common linker errors such as:
  - `undefined reference to main`
  - `undefined reference to Class::method()`

### 2. Error Classification
Learned to classify errors into:
- Compile-time errors (syntax, missing includes, type issues)
- Link-time errors (missing definitions, missing object files)
- Runtime errors (logic errors, invalid lifetimes)

This classification significantly reduces debugging time.

---

### 3. Debugging Strategy
Practiced a structured approach to debugging:
1. Identify whether the issue is compile-time, link-time, or runtime
2. Focus on the first meaningful error message
3. Check recent changes
4. Verify file ownership and dependencies

---

### 4. Build System Understanding
- Manual compilation using `g++ -c`
- Linking object files into an executable
- Understanding why a program must have exactly one `main()`
- Introduction to Makefiles and dependency-based builds

---

## Interview-Style Reasoning Practiced
- Explaining build failures clearly
- Reasoning about missing symbols
- Discussing ownership, lifetimes, and safety implications
- Communicating debugging steps effectively

---

## Key Takeaways
- Debugging is a reasoning skill, not guesswork
- Understanding the build process removes fear of large codebases
- Calm, systematic thinking is critical in robotics and safety-critical software
- Not every productive day results in code; some result in deeper understanding

---

## Status

✔ Day 7 completed  
✔ Debugging concepts understood  
✔ Build and linker behavior demystified  
✔ Ready to move into modern C++ memory management and RAII
