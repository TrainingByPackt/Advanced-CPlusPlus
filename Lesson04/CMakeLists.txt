#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Description : Lesson 4 build file
#============================================================================
cmake_minimum_required(VERSION 3.11.0)

project(Lesson03
  VERSION 0.1.0.0
  DESCRIPTION "Lesson 4 of Advanced C++ course."
)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)


if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

# ------------------------------------------------------------------
# Exercise 1
# ------------------------------------------------------------------
add_executable(Exercise1 ex1/exercise1.cpp ex1/kitchen.cpp ex1/kitchenImpl.cpp)

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

