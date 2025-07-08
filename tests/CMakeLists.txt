# Test configuration for Chess Game
cmake_minimum_required(VERSION 3.10)

# Find Google Test framework
find_package(GTest QUIET)

if(GTest_FOUND)
    message(STATUS "Google Test found, enabling unit tests")
    
    # Enable testing
    enable_testing()
    
    # Include directories
    include_directories(${CMAKE_SOURCE_DIR}/src)
    include_directories(${CMAKE_SOURCE_DIR}/include)
    
    # Collect test source files
    file(GLOB_RECURSE TEST_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
    )
    
    # Collect main source files (excluding main.cpp if it exists)
    file(GLOB_RECURSE MAIN_SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/*.cc"
    )
    
    # Remove main.cpp from sources if it exists
    list(FILTER MAIN_SOURCES EXCLUDE REGEX ".*main\\.cpp$")
    
    if(TEST_SOURCES)
        # Create test executable
        add_executable(chess_tests ${TEST_SOURCES} ${MAIN_SOURCES})
        
        # Link with Google Test
        target_link_libraries(chess_tests 
            GTest::GTest 
            GTest::Main
        )
        
        # Add tests to CTest
        add_test(NAME ChessGameTests COMMAND chess_tests)
        
        # Set test properties
        set_tests_properties(ChessGameTests PROPERTIES
            TIMEOUT 60
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
        
        message(STATUS "Chess game tests configured successfully")
    else()
        message(STATUS "No test files found in tests directory")
    endif()
    
else()
    message(STATUS "Google Test not found, tests will not be built")
    message(STATUS "To install Google Test on Ubuntu: sudo apt-get install libgtest-dev")
    message(STATUS "To install Google Test on macOS: brew install googletest")
endif()

# Create example test files if directory is empty
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/example_test.cpp)
    message(STATUS "Creating example test file")
endif()