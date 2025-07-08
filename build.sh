#!/bin/bash

# Chess Game OOP - Quick Build Script
# This script provides a simple way to build the project with common configurations

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Default values
BUILD_TYPE="Release"
CLEAN=false
RUN_TESTS=false
PARALLEL_JOBS=$(nproc 2>/dev/null || echo 4)

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to show usage
show_usage() {
    echo "Chess Game OOP Build Script"
    echo ""
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "OPTIONS:"
    echo "  -t, --type TYPE     Build type: Debug, Release, RelWithDebInfo (default: Release)"
    echo "  -c, --clean         Clean build directory before building"
    echo "  -j, --jobs N        Number of parallel jobs (default: $PARALLEL_JOBS)"
    echo "  -r, --run-tests     Run tests after building"
    echo "  -h, --help          Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                           # Release build"
    echo "  $0 -t Debug -r              # Debug build with tests"
    echo "  $0 --clean --type Release   # Clean release build"
    echo ""
}

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -t|--type)
            BUILD_TYPE="$2"
            shift 2
            ;;
        -c|--clean)
            CLEAN=true
            shift
            ;;
        -j|--jobs)
            PARALLEL_JOBS="$2"
            shift 2
            ;;
        -r|--run-tests)
            RUN_TESTS=true
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        *)
            print_error "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# Validate build type
case $BUILD_TYPE in
    Debug|Release|RelWithDebInfo|MinSizeRel)
        ;;
    *)
        print_error "Invalid build type: $BUILD_TYPE"
        echo "Valid types: Debug, Release, RelWithDebInfo, MinSizeRel"
        exit 1
        ;;
esac

# Get script directory
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
PROJECT_ROOT="$SCRIPT_DIR"

print_status "Building Chess Game OOP"
print_status "Build type: $BUILD_TYPE"
print_status "Parallel jobs: $PARALLEL_JOBS"

# Create build directory
BUILD_DIR="$PROJECT_ROOT/build"

if [ "$CLEAN" = true ]; then
    print_status "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure project
print_status "Configuring project..."
cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      "$PROJECT_ROOT"

if [ $? -ne 0 ]; then
    print_error "CMake configuration failed!"
    exit 1
fi

# Build project
print_status "Building project..."
cmake --build . --config "$BUILD_TYPE" -j "$PARALLEL_JOBS"

if [ $? -ne 0 ]; then
    print_error "Build failed!"
    exit 1
fi

print_success "Build completed successfully!"

# Check if executable was created
if [ -f "chess_game" ]; then
    print_success "Executable created: $BUILD_DIR/chess_game"
else
    print_warning "Executable not found (this is normal if no source files exist yet)"
fi

# Run tests if requested
if [ "$RUN_TESTS" = true ]; then
    print_status "Running tests..."
    if command -v ctest &> /dev/null; then
        ctest --verbose
        if [ $? -eq 0 ]; then
            print_success "All tests passed!"
        else
            print_warning "Some tests failed"
        fi
    else
        print_warning "CTest not found - skipping tests"
    fi
fi

# Display build information
echo ""
print_success "Build Summary:"
echo "  Project: Chess Game OOP"
echo "  Build Type: $BUILD_TYPE"
echo "  Build Directory: $BUILD_DIR"
echo "  Compiler: $(cmake --version | head -n1)"

if [ -f "compile_commands.json" ]; then
    echo "  Compile commands: $BUILD_DIR/compile_commands.json"
fi

echo ""
print_status "To run the game (when implemented):"
echo "  cd $BUILD_DIR && ./chess_game"
echo ""
print_status "To run tests:"
echo "  cd $BUILD_DIR && ctest --verbose"
echo ""