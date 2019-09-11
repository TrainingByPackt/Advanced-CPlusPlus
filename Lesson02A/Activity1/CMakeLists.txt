#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 1 build file
#============================================================================
cmake_minimum_required(VERSION 3.11.0)

project(Activty01
  VERSION 0.1.0.0
  DESCRIPTION "Activity 1 for Lesson 2 of Advanced C++ course."
)
set(Activty02_VENDOR "Brian Price")


set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

include(FetchContent)

# ------------------------------------------------------------------
# Activity 1
# ------------------------------------------------------------------
add_executable(graphics matrix3d.cpp point3d.cpp main.cpp)
find_package(GTest)

enable_testing()
add_subdirectory(tests)


