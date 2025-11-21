# Test Workspace Guide

These exercises were prepared as tests for the new Software Engineer position at MED-EL and are intended to run inside the supplied GitHub Codespaces development container (`.devcontainer/`). The container is based on Ubuntu 22.04 with CMake, GCC, Clang, and Python preinstalled. Open the repository in Codespaces, let the container build, then follow the instructions below from the integrated terminal (`bash`).

## Container quick start
- Open the repository in GitHub Codespaces (or locally with VS Code Remote - Containers).
- Wait for the dev container build to finish; it runs `cmake -S . -B build` automatically at the workspace root.
- Use the terminal within the container for all commands below.

## CPP_TEST/TEST1
A CMake-based C++17 application that builds the executable `LibraryManagement`.

**Build and Run**
```bash
# From the repository root
cd CPP_TEST/TEST1
cmake -S . -B build
cmake --build build

# Run the executable (update the path if your generator adds Debug/Release folders)
./build/LibraryManagement
```
If you selected the Ninja or Unix Makefiles generator (default in the container), the binary will be at `build/LibraryManagement`.

## CPP_TEST/TEST2
A single-file C++17 example that can be compiled directly with `g++` or `clang++`.

**Compile and Run**
```bash
# From the repository root
cd CPP_TEST/TEST2
g++ -std=c++17 -O2 main.cpp -o CoinChange
./CoinChange
```

## PYTH_TEST/TEST1
A Python script that generates and visualises random image data.

The Codespaces container already includes the `numpy`, `seaborn`, and `matplotlib` packages.

**Run the script**
```bash
# From the repository root
cd PYTH_TEST/TEST1
python3 ll.py
```
The script displays a heatmap window; close it to finish execution.

---
All commands assume you are running inside the dev container workspace root. Adjust paths if you launch tools from subdirectories.
