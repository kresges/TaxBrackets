cmake_minimum_required(VERSION 2.8.9)

include_directories(app taxBrackets)

file(GLOB SOURCES "app/src/*.cpp" "taxBrackets/src/*.cpp")
#file(GLOB SOURCES "taxBrackets/src/*.cpp")
file(GLOB TESTS "test/*.cpp")

set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set(CMAKE_CXX_STANDARD 11)
project(taxes)

add_executable(taxes ${SOURCES})
add_library(taxes_lib ${SOURCES})

### TESTING ###
add_subdirectory(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

### UNIT TESTS ###
add_executable(unitTests ${TESTS})
target_link_libraries(unitTests gtest gtest_main)
target_link_libraries(unitTests taxes_lib)
add_test(runTests unitTests)
