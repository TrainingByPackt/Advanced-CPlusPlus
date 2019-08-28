#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 1 tests build file
#============================================================================include(GoogleTest)
add_executable(graphicstests matrix3dTests.cpp ../matrix3d.cpp point3dTests.cpp ../point3d.cpp serialisationTests.cpp)
target_link_libraries(graphicstests GTest::GTest GTest::Main)

if(EXISTS ${nlohmann_json_SOURCE_DIR})
  target_include_directories(graphicstests PRIVATE ${nlohmann_json_SOURCE_DIR}/include)
endif()

gtest_discover_tests(graphicstests)
