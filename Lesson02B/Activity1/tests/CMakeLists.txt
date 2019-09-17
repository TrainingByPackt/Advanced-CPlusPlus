#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 2 Activity 1 tests build file
#============================================================================
include(GoogleTest)

SET(SRC_FILES )

SET(TEST_FILES 
    containsTests.cpp
    )

add_executable(containstests 
    ${SRC_FILES}
    ${TEST_FILES}
    )

target_link_libraries(containstests GTest::GTest GTest::Main)

gtest_discover_tests(containstests)
