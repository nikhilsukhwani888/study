#!/usr/bin/env bash

set -euo pipefail

# Build configuration
BUILD_DIR="${BUILD_DIR:-build}"
CMAKE_GENERATOR="${CMAKE_GENERATOR:-MinGW Makefiles}"
BUILD_TYPE="${BUILD_TYPE:-Release}"
EXECUTABLE_NAME="${EXECUTABLE_NAME:-study.exe}"

# Compiler paths (default: mingw64)
CMAKE_C_COMPILER="${CMAKE_C_COMPILER:-/c/msys64/mingw64/bin/gcc.exe}"
CMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER:-/c/msys64/mingw64/bin/g++.exe}"
CMAKE_MAKE_PROGRAM="${CMAKE_MAKE_PROGRAM:-/c/msys64/mingw64/bin/mingw32-make.exe}"

# Ensure PATH includes mingw64 bin
export PATH="/c/msys64/mingw64/bin:$PATH"

echo "========================================"
echo "Build Configuration"
echo "========================================"
echo "Build directory: $BUILD_DIR"
echo "CMake generator: $CMAKE_GENERATOR"
echo "Build type: $BUILD_TYPE"
echo "C compiler: $CMAKE_C_COMPILER"
echo "CXX compiler: $CMAKE_CXX_COMPILER"
echo "Make program: $CMAKE_MAKE_PROGRAM"
echo "========================================"

# Find CMake executable
CMAKE_EXE="${CMAKE_EXE:-cmake}"
if ! command -v "$CMAKE_EXE" >/dev/null 2>&1; then
  if [ -x "/c/Program Files/CMake/bin/cmake.exe" ]; then
    CMAKE_EXE="/c/Program Files/CMake/bin/cmake.exe"
  elif [ -x "C:/Program Files/CMake/bin/cmake.exe" ]; then
    CMAKE_EXE="C:/Program Files/CMake/bin/cmake.exe"
  else
    echo "ERROR: cmake not found in PATH" >&2
    exit 1
  fi
fi

echo "Using cmake: $CMAKE_EXE"

# Clean build directory (remove cache to avoid compiler mismatches)
echo ""
echo "Cleaning old build directory..."
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Configure with CMake
echo ""
echo "Configuring with CMake..."
"$CMAKE_EXE" -S . -B "$BUILD_DIR" \
  -G "$CMAKE_GENERATOR" \
  -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
  -DCMAKE_C_COMPILER="$CMAKE_C_COMPILER" \
  -DCMAKE_CXX_COMPILER="$CMAKE_CXX_COMPILER" \
  -DCMAKE_MAKE_PROGRAM="$CMAKE_MAKE_PROGRAM"

# Build project
echo ""
echo "Building project..."
"$CMAKE_EXE" --build "$BUILD_DIR" --config "$BUILD_TYPE"

# Find and run executable
echo ""
echo "Locating executable..."
if [ -f "$BUILD_DIR/$EXECUTABLE_NAME" ]; then
  EXE_PATH="$BUILD_DIR/$EXECUTABLE_NAME"
elif [ -f "$BUILD_DIR/study.exe" ]; then
  EXE_PATH="$BUILD_DIR/study.exe"
else
  EXE_PATH=$(find "$BUILD_DIR" -maxdepth 1 -type f -name "*.exe" -print -quit || true)
  if [ -z "$EXE_PATH" ]; then
    echo "ERROR: No executable found in $BUILD_DIR" >&2
    exit 1
  fi
fi

echo "Running: $EXE_PATH"
echo ""
"$EXE_PATH"

exit 0
