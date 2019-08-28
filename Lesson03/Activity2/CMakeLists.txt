#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 Activity 2 build file
#============================================================================
cmake_minimum_required(VERSION 3.11.0)

project(Activty02
  VERSION 0.1.0.0
  DESCRIPTION "Activity 2 for Lesson 3 of Advanced C++ course."
)
set(Activty02_VENDOR "Brian Price")
set(PROJECT_VENDOR "${CxxSimulator_VENDOR}")


set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()


# ------------------------------------------------------------------
# Activity 2
# ------------------------------------------------------------------
add_executable(datetools date.cpp main.cpp)
find_package(GTest)

enable_testing()
add_subdirectory(tests)

