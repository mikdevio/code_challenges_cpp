# Code Challenges in C/C++

# 🚀 Code Challenges - C/C++

This repository provides a highly structured and automated environment for solving and testing code challenges from platforms like **LeetCode**, **CodeWars**, and **Codeforces**. It uses **C++17**, **CMake**, and the **Catch2** unit testing framework.

The architecture is designed to keep solutions and their respective unit tests coupled within the same directory, enabling isolated development and instant logic verification.

---

## 📂 Project Structure

All source code is centralized inside the `src/` directory to keep the project root clean from temporary compilation files:

```text
📦 code-challenges-cpp
 ┣ 📂 src
 ┃ ┣ 📂 codewars_katas         # Challenges from CodeWars
 ┃ ┃ ┗ 📂 001_two_array_sum
 ┃ ┃ ┃ ┣ 📜 CMakeLists.txt    # Challenge-specific compilation build script
 ┃ ┃ ┃ ┣ 📜 solution.cpp      # Implementation logic
 ┃ ┃ ┃ ┗ 📜 solution_test.cpp # Unit tests (Catch2)
 ┃ ┣ 📂 leetcode_problems     # Challenges from LeetCode
 ┃ ┣ 📂 codeforces_problems   # Challenges from Codeforces
 ┃ ┣ 📂 tests_common          # Global Catch2 test entry point
 ┃ ┗ 📜 CMakeLists.txt        # Central index of all challenges
 ┣ 📜 build.sh                # Automation script for a clean build and test run
 ┣ 📜 create_challenge.sh     # Automation script to scaffold new challenges
 ┣ 📜 CMakeLists.txt          # Main root CMake configuration
 ┗ 📜 .gitignore              # Git ignore rules
```

---

## 🛠️ Prerequisites (Arch Linux)

The environment relies on the native packages provided by the operating system. Ensure you have the core tools installed by running:

```bash
sudo pacman -Syu base-devel cmake git gcc catch2
```

---

## 🚀 Workflow and Automation

To eliminate repetitive copying and pasting tasks, the project includes Bash scripts that manage the entire development lifecycle.

### 1. Scaffold a New Challenge
To instantly generate the directory, base source files, tests, and local CMake configuration for a new problem, run this command from the root:

```bash
./create_challenge.sh <platform> <id_name> <main_function_name>
```

**Practical Example:**
```bash
./create_challenge.sh leetcode_problems 001_two_array_sum sumTwoArrays
```
*This command creates the folder, setups template files, and automatically registers the new directory inside `src/CMakeLists.txt`.*

### 2. Compile and Run Tests
To clear old cache, compile all solutions in parallel using all available CPU cores, and trigger the test suite, run:

```bash
./build.sh
```

Once compilation is done, the script will prompt you to run `ctest`. Replying with `y` or `s` will display the comprehensive test report for all your solutions.

---

## 🧪 Unit Testing Sample (Catch2)

Tests are written using the modern and clean syntax of **Catch2 v3**:

```cpp
#include <catch2/catch_test_macros.hpp>
#include <vector>

// Declaration of the target function
int sumTwoArrays(const std::vector<int>& arr1, const std::vector<int>& arr2);

TEST_CASE("Summing two arrays", "[codewars]") {
    SECTION("Valid integer inputs") {
        std::vector<int> a = {1, 2, 3};
        std::vector<int> b = {4, 5};
        REQUIRE(sumTwoArrays(a, b) == 15);
    }
}
```
