include(GoogleTest)
add_executable(tests 
  CanTest.cpp 
  SumFuncTest.cpp 
  ../src/SumFunc.cpp
  LinearMotion1DTest.cpp
  ../src/LinearMotion1D.cpp
)
target_link_libraries(tests GTest::GTest)
gtest_discover_tests(tests)
