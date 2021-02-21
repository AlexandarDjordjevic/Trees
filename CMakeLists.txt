cmake_minimum_required(VERSION 3.8)

project(Trees)

set(this Trees)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(include
    include/Trees/BST.hpp
)

set(source
    examples/double.cpp
)

add_executable(example_int examples/BST/int.cpp)
target_include_directories(example_int PUBLIC include)

add_executable(example_double examples/BST/double.cpp)
target_include_directories(example_double PUBLIC include)

#target_link_libraries(${this})

add_subdirectory(tests)
