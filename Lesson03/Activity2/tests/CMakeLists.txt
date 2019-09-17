#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 2 tests build file
#============================================================================
include(GoogleTest)
add_executable(datetoolstests dateTests.cpp ../date.cpp)
target_link_libraries(datetoolstests GTest::GTest GTest::Main)

gtest_discover_tests(datetoolstests)
