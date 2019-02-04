cmake_minimum_required(VERSION 2.8.9)

include_directories(app finTools)

file(GLOB SOURCES "app/src/*.cpp")


set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set( CMAKE_CXX_STANDARD 11 )

project(finApp)

#set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib" )
#set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib" )

#finTools
add_subdirectory(finTools)

add_executable(finApp ${SOURCES})
target_link_libraries( finApp finTools_lib )

### TESTING ###
add_subdirectory(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} finTools_lib)

#[[
include_directories(app finTools/taxBrackets)

file(GLOB SOURCES "app/src/*.cpp" "finTools/taxBrackets/src/*.cpp")

file(GLOB TESTS "test/*.cpp")

set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set( CMAKE_CXX_STANDARD 11 )
set( BOOST_ROOT "/usr/local/include/" )

project(taxes)

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib" )

add_executable(taxes ${SOURCES})
target_link_libraries(taxes ${Boost_LIBRARIES})
add_library(taxes_lib ${SOURCES})

### TESTING ###
add_subdirectory(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} taxBrackets)

### UNIT TESTS ###
add_executable(unitTests ${TESTS})
target_link_libraries(unitTests gtest gtest_main)
target_link_libraries(unitTests taxes_lib)
add_test(runTests unitTests)
]]
