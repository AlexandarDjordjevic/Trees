cmake_minimum_required(VERSION 3.8)


set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


set(source
        bst_tests.cpp
    )

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(bst_tests ${source})

target_include_directories(bst_tests PUBLIC ../include)

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(
    bst_tests
    ${GTEST_BOTH_LIBRARIES}
    pthread
)

add_test(
    NAME ${this}
    COMMAND ${this}
)