include(GoogleTest)
add_executable(L3Ex4tests StackTests.cpp)
target_link_libraries(L3Ex4tests GTest::GTest GTest::Main)
gtest_discover_tests(L3Ex4tests)
