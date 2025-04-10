cmake_minimum_required(VERSION 3.10)
project(MyCppProject LANGUAGES CXX)

# Enable C++23 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add GoogleTest
add_subdirectory(extern/googletest)

# Enable testing
enable_testing()

# Configure library
add_library(MyLibrary INTERFACE)
target_include_directories(MyLibrary INTERFACE include)

# Configure tests
add_executable(MyLibraryTests
    tests/test_basic.cpp
)

target_link_libraries(MyLibraryTests
    PRIVATE
    MyLibrary
    gtest
    gtest_main
)

# Enable CTest integration
include(GoogleTest)
gtest_discover_tests(MyLibraryTests)