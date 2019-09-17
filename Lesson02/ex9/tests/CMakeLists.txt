include(GoogleTest)
add_executable(tests9 StackTests.cpp)
target_link_libraries(tests9 GTest::GTest GTest::Main)
gtest_discover_tests(tests9)
