#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Description : Lesson 4 Activity 1 tests build file
#============================================================================
include(GoogleTest)

SET(TEST_FILES delegateTests.cpp) 

add_executable(L4delegatesTests
    ${TEST_FILES}
    )

target_link_libraries(L4delegatesTests GTest::GTest GTest::Main)

gtest_discover_tests(L4delegatesTests)
