cmake_minimum_required(VERSION 3.20)
project(Csv)

set(CMAKE_CXX_STANDARD 23)

add_executable(MAIN main.cpp)

add_library(CSV Csv.cpp Csv.h tests.cpp tests.h)

add_subdirectory(tests/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(CSV gtest gtest_main)

add_subdirectory(logger)
target_link_libraries(MAIN  CSV mainlogger)