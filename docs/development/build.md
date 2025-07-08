# Build Instructions

This document provides detailed instructions for building the Chess Game OOP project on different platforms.

## 📋 Prerequisites

### Required Tools
- **C++ Compiler**: GCC 7+, Clang 5+, or MSVC 2017+
- **CMake**: Version 3.10 or higher
- **Git**: For version control
- **Make**: Or Ninja build system

### Optional Tools
- **Google Test**: For unit testing
- **Doxygen**: For documentation generation
- **Valgrind**: For memory analysis (Linux)
- **Clang-tidy**: For static analysis

## 🖥️ Platform-Specific Setup

### Ubuntu/Debian
```bash
# Install required packages
sudo apt update
sudo apt install build-essential cmake git

# Optional: Install testing and documentation tools
sudo apt install libgtest-dev doxygen graphviz
sudo apt install clang-tidy valgrind

# Build and install Google Test (if not available via package manager)
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp lib/*.a /usr/lib
```

### CentOS/RHEL/Fedora
```bash
# CentOS/RHEL
sudo yum groupinstall "Development Tools"
sudo yum install cmake git

# Fedora
sudo dnf groupinstall "Development Tools"
sudo dnf install cmake git

# Optional tools
sudo yum install gtest-devel doxygen graphviz  # CentOS/RHEL
sudo dnf install gtest-devel doxygen graphviz  # Fedora
```

### macOS
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install Homebrew (if not already installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install required tools
brew install cmake git

# Optional tools
brew install googletest doxygen graphviz
```

### Windows

#### Using Visual Studio
1. Install Visual Studio 2017 or later with C++ support
2. Install CMake from https://cmake.org/download/
3. Install Git from https://git-scm.com/download/win

#### Using MinGW-w64
```bash
# Install MSYS2 from https://www.msys2.org/
# Then in MSYS2 terminal:
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-cmake
pacman -S mingw-w64-x86_64-make
pacman -S git
```

## 🔨 Building the Project

### Basic Build

#### Linux/macOS
```bash
# Clone the repository
git clone https://github.com/TruongMinhHuy/Nhom3_OOP.git
cd Nhom3_OOP

# Create build directory
mkdir build && cd build

# Configure project
cmake ..

# Build the project
make -j$(nproc)  # Linux
make -j$(sysctl -n hw.ncpu)  # macOS
```

#### Windows (Visual Studio)
```cmd
REM Clone the repository
git clone https://github.com/TruongMinhHuy/Nhom3_OOP.git
cd Nhom3_OOP

REM Create build directory
mkdir build && cd build

REM Configure project
cmake ..

REM Build the project
cmake --build . --config Release
```

### Build Configurations

#### Debug Build
```bash
mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(nproc)
```

#### Release Build
```bash
mkdir build-release && cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
```

#### Release with Debug Info
```bash
mkdir build-relwithdebinfo && cd build-relwithdebinfo
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
make -j$(nproc)
```

### Advanced Build Options

#### Custom Compiler
```bash
# Using specific compiler
cmake -DCMAKE_CXX_COMPILER=clang++ ..

# Using specific C++ standard
cmake -DCMAKE_CXX_STANDARD=17 ..
```

#### Enable Testing
```bash
# Build with tests (requires Google Test)
cmake -DENABLE_TESTING=ON ..
make -j$(nproc)

# Run tests
ctest --verbose
```

#### Generate Documentation
```bash
# Build documentation (requires Doxygen)
cmake -DBUILD_DOCUMENTATION=ON ..
make docs
```

## 🎯 Build Targets

### Available Targets
```bash
# Build main executable (when source files exist)
make chess_game

# Build tests
make chess_tests

# Generate documentation
make docs

# Clean build artifacts
make clean

# Clean everything including build directory
make clean-all
```

### Running the Application
```bash
# After successful build
./chess_game           # Linux/macOS
./chess_game.exe       # Windows
```

## 🔍 Troubleshooting

### Common Issues

#### CMake Version Too Old
```
Error: CMake 3.10 or higher is required
```
**Solution**: Update CMake to version 3.10+

#### Compiler Not Found
```
Error: C++ compiler not working
```
**Solutions**:
- Install development tools package
- Set `CMAKE_CXX_COMPILER` explicitly
- Check PATH environment variable

#### Google Test Not Found
```
Warning: Google Test not found, tests will not be built
```
**Solutions**:
- Install Google Test development package
- Build Google Test from source
- Disable testing with `-DENABLE_TESTING=OFF`

#### Missing Standard Library Headers
```
Error: 'memory' file not found
```
**Solution**: Install complete C++ standard library
```bash
# Ubuntu/Debian
sudo apt install libc++-dev

# CentOS/RHEL
sudo yum install libstdc++-devel
```

### Build Performance Issues

#### Slow Compilation
- Use parallel builds: `make -j$(nproc)`
- Use faster linker: `cmake -DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=gold" ..`
- Enable precompiled headers (future enhancement)

#### Large Binary Size
- Use Release build: `-DCMAKE_BUILD_TYPE=Release`
- Strip symbols: `cmake -DCMAKE_CXX_FLAGS_RELEASE="-O3 -DNDEBUG -s" ..`

## 📊 Build Verification

### Verify Build Success
```bash
# Check if executable was created
ls -la build/chess_game

# Run basic functionality test
./build/chess_game --help

# Run unit tests (if built)
cd build && ctest --verbose
```

### Performance Benchmarks
```bash
# Compile with optimizations
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)

# Run performance tests
time ./chess_game < test_input.txt
```

## 🛠️ Development Builds

### Debug Configuration
```bash
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_FLAGS_DEBUG="-g -O0 -Wall -Wextra" \
      ..
```

### Static Analysis
```bash
# Using clang-tidy
cmake -DCMAKE_CXX_CLANG_TIDY="clang-tidy" ..

# Using cppcheck
cppcheck --enable=all src/
```

### Memory Analysis
```bash
# Using Valgrind (Linux)
valgrind --leak-check=full ./chess_game

# Using AddressSanitizer
cmake -DCMAKE_CXX_FLAGS="-fsanitize=address" ..
```

## 📦 Packaging

### Creating Distribution Package
```bash
# Using CPack
cmake -DCMAKE_BUILD_TYPE=Release ..
make package
```

### Installation
```bash
# System-wide installation
sudo make install

# Custom prefix
cmake -DCMAKE_INSTALL_PREFIX=/opt/chess_game ..
make install
```

## 🔄 Continuous Integration

### GitHub Actions Example
```yaml
name: Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Install dependencies
      run: |
        sudo apt update
        sudo apt install build-essential cmake libgtest-dev
    
    - name: Create build directory
      run: mkdir build
    
    - name: Configure
      run: cd build && cmake ..
    
    - name: Build
      run: cd build && make -j$(nproc)
    
    - name: Test
      run: cd build && ctest --verbose
```

## 📝 Build Scripts

### Automated Build Script
```bash
#!/bin/bash
# build.sh - Automated build script

set -e

BUILD_TYPE=${1:-Release}
BUILD_DIR="build-${BUILD_TYPE,,}"

echo "Building Chess Game OOP (${BUILD_TYPE})"

# Create and enter build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure
cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" ..

# Build
make -j$(nproc)

# Test (if available)
if command -v ctest &> /dev/null; then
    echo "Running tests..."
    ctest --verbose
fi

echo "Build completed successfully!"
echo "Executable: $PWD/chess_game"
```

This comprehensive build guide ensures that developers can successfully build and run the Chess Game OOP project on any supported platform.