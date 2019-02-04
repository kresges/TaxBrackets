cmake_minimum_required( VERSION 2.8.9 )

#file(GLOB SOURCES "taxBrackets/src/*.cpp")
#file(GLOB TESTS "taxBrackets/gtests/*.cpp")

set( CMAKE_CXX_COMPILER "/usr/bin/g++" )
set( CMAKE_CXX_STANDARD 11 )
set( BOOST_ROOT "/usr/local/include/" )

project( finTools )

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib" )

#add_library(finTools_lib ${SOURCES})
add_library( finTools_lib taxBrackets/src/taxBrackets.cpp )
target_include_directories( finTools_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries( finTools_lib ${Boost_LIBRARIES} )

### UNIT TESTS ###
add_executable( unitTests taxBrackets/gtests/test_taxBrackets.cpp )
target_link_libraries(unitTests gtest gtest_main )
target_link_libraries(unitTests finTools_lib )
add_test( runTests unitTests )
