include(GoogleTest)
add_executable(L2BEx4tests StackTests.cpp)
target_link_libraries(L2BEx4tests GTest::GTest GTest::Main)
gtest_discover_tests(L2BEx4tests)
