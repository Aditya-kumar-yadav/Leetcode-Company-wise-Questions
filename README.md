<div align="center">

# 🚀 DSA Engineering: C++ Architecture

[![CI Pipeline](https://github.com/Aditya-kumar-yadav/dsa-engineering-cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/Aditya-kumar-yadav/dsa-engineering-cpp/actions)
[![Language](https://img.shields.io/badge/Language-C%2B%2B17-00599C.svg?logo=c%2B%2B)](https://isocpp.org/)
[![Build System](https://img.shields.io/badge/Build-CMake-064F8C.svg?logo=cmake)](https://cmake.org/)
[![Testing](https://img.shields.io/badge/Testing-GoogleTest-209E5A.svg?logo=testing-library)](https://github.com/google/googletest)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)]()

**A scalable, fully automated architecture for Data Structures and Algorithms (DSA) utilizing modern software engineering practices.**

</div>

---

## 📖 Overview

This repository is built on a core philosophy: **Algorithms should be treated with the exact engineering rigor required in top-tier backend environments.** 

Instead of serving as a static archive of competitive programming solutions, this repository enforces production-grade enterprise constraints. Every implementation is subjected to **Test-Driven Development (TDD)**, validated by **Continuous Integration (CI/CD)** pipelines, and managed through a **Dynamic Build System**.

---

## ✨ Core Engineering Features

* ⚡ **Modern Standards:** Highly optimized **C++17** solutions designed for minimal latency and strict space/time complexity.
* 🧪 **Automated Validation:** Comprehensive unit testing infrastructure powered by **Google Test (gtest)** to guarantee edge-case resilience.
* 🛡️ **Memory Safety:** CI/CD pipelines fortified with **AddressSanitizer (ASan)** and **UndefinedBehaviorSanitizer (UBSan)** to ensure leak-free, production-safe memory management.
* 🏗️ **Dynamic Compilation:** Zero-touch, cross-platform build configurations orchestrated by **CMake**.
* 🔄 **CI/CD Integration:** Autonomous pipeline execution via **GitHub Actions** upon every commit and pull request.
* 🤖 **Self-Documenting:** Custom Python tooling (`/scripts`) that autonomously extracts metadata, generates indexes, and updates markdown documentation.

---

## 🏛️ System Architecture

Our modular directory structure enforces a strict separation of concerns between source code, test assertions, and automation logic:

```text
📦 dsa-engineering-cpp
 ┣ 📂 .github/workflows   # GitHub Actions CI/CD deployment pipelines
 ┣ 📂 hubs                # Auto-generated company & topic indexing
 ┣ 📂 metadata            # Central JSON database tracking all solutions
 ┣ 📂 scripts             # Python automation and repository utilities
 ┣ 📂 src                 # Core C++ algorithmic implementations (.hpp)
 ┣ 📂 tests               # Google Test assertions and test suites (_test.cpp)
 ┣ 📜 CMakeLists.txt      # Master dynamic build configuration
 ┣ 📜 CONTRIBUTING.md     # Developer workflow and Git hygiene standards
 ┗ 📜 README.md           # Autonomously updated entry point
```

---

## ⚙️ The Engineering Lifecycle

Our workflow guarantees that the main branch remains stable and production-ready at all times:

```text
[ 💡 Problem Solved ] ➔ [ 🧪 Google Tests Written ] ➔ [ 📝 Git Commit & Push ]
                                                                 ⬇
[ 📄 Docs Regenerated ] ⬅ [ 📊 Metadata Extracted ] ⬅ [ ⚙️ CI: CMake + Tests Pass ]
```

### 🔧 Automation Tooling
The `/scripts` directory operates as the autonomous brain of this repository:
* `start.py`: Scaffolds C++ boilerplate and test environments, strictly enforcing naming conventions.
* `auto_discover.py`: A pipeline gatekeeper that scans for duplicate IDs and validates JSON metadata integrity.
* `generate_docs.py`: Autonomously builds Markdown tables, updates hubs, and maintains the global repository index.

---

## 🛠️ Local Development Setup

### Prerequisites
* **CMake** (v3.14+)
* **Python** (v3.10+)
* **C++17** compatible compiler (GCC, Clang, or MSVC)

### Quick Start

```bash
# 1. Clone the repository
git clone https://github.com/Aditya-kumar-yadav/dsa-engineering-cpp.git
cd dsa-engineering-cpp

# 2. Configure the build environment
cmake -B build -S .

# 3. Compile the project
cmake --build build

# 4. Execute the test suite locally
cd build && ctest --output-on-failure
```

---

## 📊 Problem Database & Analytics

Our CI/CD pipeline autonomously maintains a central index that tracks difficulty curves, company-wise problem frequencies, and granular algorithm categorization. 

📄 **[View the Complete Solution Index](./src/README.md)** *(Autonomously generated upon successful merge)*
