cmake_minimum_required(VERSION 3.10)
project(complex_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка статической компоновки для всех компонентов
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)

# Добавление Google Test
add_subdirectory(external/googletest)

# Создание библиотеки
add_library(complex_lib library.cpp)
target_include_directories(complex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Создание тестов
enable_testing()
add_executable(complex_tests tests/test_basic.cpp)
target_link_libraries(complex_tests complex_lib gtest gtest_main)

add_test(NAME complex_tests COMMAND complex_tests)
