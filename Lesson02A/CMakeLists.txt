#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Copyright   : Your copyright notice
# Description : Lesson 2 build file
#============================================================================
# Helper file only - not good example of Cmake file
cmake_minimum_required(VERSION 3.11.0)

project(Lesson02
  VERSION 0.1.0.0
  DESCRIPTION "Lesson 2 of Advanced C++ course."
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
add_executable(Exercise1 ex1/exercise1.cpp)

# ------------------------------------------------------------------
# Exercise 2
# ------------------------------------------------------------------
add_executable(Exercise2 ex2/exercise2.cpp)

# ------------------------------------------------------------------
# Exercise 3
# ------------------------------------------------------------------
add_executable(Exercise3 ex3/exercise3.cpp)

# ------------------------------------------------------------------
# Exercise 4
# ------------------------------------------------------------------
add_executable(Exercise4 ex4/exercise4.cpp)

# ------------------------------------------------------------------
# Exercise 5
# ------------------------------------------------------------------
add_executable(Exercise5 ex5/exercise5.cpp)

# ------------------------------------------------------------------
# Exercise 6
# ------------------------------------------------------------------
add_executable(Exercise6 ex6/exercise6.cpp)

# ------------------------------------------------------------------
# Exercise 7
# ------------------------------------------------------------------
add_executable(Exercise7 ex7/exercise7.cpp ex7/Fraction.cpp)
find_package(GTest)

enable_testing()
add_subdirectory(ex7/tests)

