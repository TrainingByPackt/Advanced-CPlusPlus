include(GoogleTest)
add_executable(tests FractionTests.cpp ../Fraction.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
gtest_discover_tests(tests)
