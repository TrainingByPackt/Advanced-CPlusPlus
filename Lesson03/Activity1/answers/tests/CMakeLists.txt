#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 1 tests build file
#============================================================================
include(GoogleTest)

SET(SRC_FILES 
    ../matrix3d.cpp 
    ../point3d.cpp)

SET(TEST_FILES 
    matrix3dTests.cpp 
    point3dTests.cpp)

add_executable(L3graphicstests 
    ${SRC_FILES}
    ${TEST_FILES}
    )

target_link_libraries(L3graphicstests GTest::GTest GTest::Main)

gtest_discover_tests(L3graphicstests)
