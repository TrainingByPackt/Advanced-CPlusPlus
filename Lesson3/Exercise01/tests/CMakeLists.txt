include(GoogleTest)
add_executable(L3Ex1tests FractionTests.cpp ../Fraction.cpp StackTests.cpp)
target_link_libraries(L3Ex1tests GTest::GTest GTest::Main)
gtest_discover_tests(L3Ex1tests)
