#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 1 build file
#============================================================================
cmake_minimum_required(VERSION 3.11.0)

project(Activty02
  VERSION 0.1.0.0
  DESCRIPTION "Activity 1 for Lesson 3 of Advanced C++ course."
)
set(Activty02_VENDOR "Brian Price")
set(PROJECT_VENDOR "${CxxSimulator_VENDOR}")


set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

include(FetchContent)

FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.6.1
)

FetchContent_GetProperties(nlohmann_json)
if(NOT nlohmann_json_POPULATED)
  FetchContent_Populate(nlohmann_json)
endif()

# ------------------------------------------------------------------
# Activity 1
# ------------------------------------------------------------------
add_executable(graphics matrix3d.cpp point3d.cpp main.cpp)
find_package(GTest)

enable_testing()
add_subdirectory(tests)

if(EXISTS ${nlohmann_json_SOURCE_DIR})
  target_include_directories(graphics PRIVATE ${nlohmann_json_SOURCE_DIR}/include)
endif()


