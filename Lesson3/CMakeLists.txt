#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 3 build file
#============================================================================
# Helper file only - not good example of Cmake file
cmake_minimum_required(VERSION 3.11.0)

project(Lesson03
  VERSION 0.1.0.0
  DESCRIPTION "Lesson 3 of Advanced C++ course."
)
set(CxxSimulator_VENDOR "Brian Price")
set(PROJECT_VENDOR "${CxxSimulator_VENDOR}")

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)


if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

# ------------------------------------------------------------------
# Exercise 1
# ------------------------------------------------------------------
find_package(GTest)

enable_testing()
add_subdirectory(ex1/tests)

# ------------------------------------------------------------------
# Exercise 2
# ------------------------------------------------------------------
add_executable(L3Exercise2 ex2/exceptions.cpp)
target_compile_options(L3Exercise2 PRIVATE $<$<CXX_COMPILER_ID:GNU>:-fpermissive>)


# ------------------------------------------------------------------
# Exercise 3
# ------------------------------------------------------------------
add_executable(L3Exercise3 ex3/exercise3.cpp ex3/monitor.cpp)

# ------------------------------------------------------------------
# Exercise 4
# ------------------------------------------------------------------
add_executable(L3Exercise4 ex4/exercise4.cpp)

# ------------------------------------------------------------------
# Exercise 5
# ------------------------------------------------------------------
add_executable(L3Exercise5 ex5/exercise5.cpp)
set_property(TARGET L3Exercise5 PROPERTY CXX_STANDARD 14)

# ------------------------------------------------------------------
# Exercise 6
# ------------------------------------------------------------------
add_executable(L3Exercise6 ex6/exercise6.cpp)
