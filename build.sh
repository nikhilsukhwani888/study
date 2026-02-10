#!/usr/bin/env bash

# Exit on error
# set -e

# Set build directory
BUILD_DIR=build

# Create build directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Configure CMake
cmake -S . -B "$BUILD_DIR" -G "MinGW Makefiles"

# Build project
cmake --build "$BUILD_DIR"

# Run the executable
"$BUILD_DIR/main.exe"
