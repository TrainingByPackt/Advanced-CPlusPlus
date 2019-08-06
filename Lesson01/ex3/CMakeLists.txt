
cmake_minimum_required(VERSION 3.10.0)

project(CxxTemplate
  VERSION 0.1.0.0
  LANGUAGES C CXX
  DESCRIPTION "A project containing the essentials for other projects"
)
set(CxxTemplate_VENDOR "Aron Rubin")
set(PROJECT_VENDOR "${CxxTemplate_VENDOR}")


set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")


if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

find_package(GTest)
if(GTEST_FOUND)
set(Gtest_FOUND TRUE)
endif()
if(GTest_FOUND)
include(GoogleTest)
endif()

include(CheckIncludeFiles)
CHECK_INCLUDE_FILES(sys/prctl.h HAVE_SYS_PRCTL_H)

find_package(Threads REQUIRED)

add_executable(CxxTemplate
  src/CxxTemplate.cpp  
  src/ANewClass.cpp
)

target_link_libraries(CxxTemplate
  PUBLIC Threads::Threads
)

include(FeatureSummary)
feature_summary(WHAT ALL)

# include(DumpProps)
# print_target_properties(diva)
# include(DumpVariables)
# dump_all_variables()



