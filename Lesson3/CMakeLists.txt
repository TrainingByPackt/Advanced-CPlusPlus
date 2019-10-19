#============================================================================
# Name        : CMakeLists.txt
# Author      : Brian Price
# Version     :
# Description : Lesson 3 build file
#============================================================================
# Helper file only - not good example of Cmake file
cmake_minimum_required(VERSION 3.11.0)

project(Lesson3
  VERSION 0.1.0.0
  DESCRIPTION "Lesson 3 of Advanced C++ course."
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
find_package(GTest)

enable_testing()
add_subdirectory(Exercise01/tests)

# ------------------------------------------------------------------
# Exercise 2
# ------------------------------------------------------------------
add_executable(L3Exercise2 Exercise02/exceptions.cpp)
target_compile_options(L3Exercise2 PRIVATE $<$<CXX_COMPILER_ID:GNU>:-fpermissive>)


# ------------------------------------------------------------------
# Exercise 3
# ------------------------------------------------------------------
add_executable(L3Exercise3 Exercise03/Exercise3.cpp Exercise03/monitor.cpp)

# ------------------------------------------------------------------
# Exercise 4
# ------------------------------------------------------------------
add_executable(L3Exercise4 Exercise04/Exercise4.cpp)

# ------------------------------------------------------------------
# Exercise 5
# ------------------------------------------------------------------
add_executable(L3Exercise5 Exercise05/Exercise5.cpp)
set_property(TARGET L3Exercise5 PROPERTY CXX_STANDARD 14)

# ------------------------------------------------------------------
# Exercise 6
# ------------------------------------------------------------------
add_executable(L3Exercise6 Exercise06/Exercise6.cpp)
