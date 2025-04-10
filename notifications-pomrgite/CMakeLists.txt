cmake_minimum_required(VERSION 3.10)
project(MyCppProject LANGUAGES CXX)

# Enable C++23 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-agnostic shared library configuration
option(BUILD_SHARED_LIBS "Build shared library" ON)

# Enable testing
enable_testing()

# Configure shared library
add_library(MyLibrary SHARED
        src/library.cpp
        include/library.hpp
)

# Public headers location
target_include_directories(MyLibrary PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Platform-specific settings
if(MSVC)
    target_compile_options(MyLibrary PRIVATE /W4 /WX)
    # Generate import library for DLL
    set_target_properties(MyLibrary PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
else()
    target_compile_options(MyLibrary PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(MyLibrary PRIVATE -fPIC)  # Needed for shared libs on Unix
endif()

# Configure tests
set(GTEST_ROOT "${CMAKE_SOURCE_DIR}/../googletest")
set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/googletest/include")
set(GTEST_LIBRARY "${GTEST_ROOT}/build/lib/Release/gtest.lib")
set(GTEST_MAIN_LIBRARY "${GTEST_ROOT}/build/lib/Release/gtest_main.lib")

add_executable(MyLibraryTests
        tests/test_basic.cpp
)

target_include_directories(MyLibraryTests PRIVATE
        ${GTEST_INCLUDE_DIR}
)

target_link_libraries(MyLibraryTests
        PRIVATE
        MyLibrary
        ${GTEST_LIBRARY}
        ${GTEST_MAIN_LIBRARY}
)

# Enable CTest integration
add_test(NAME MyLibraryTests COMMAND MyLibraryTests)