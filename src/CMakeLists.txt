cmake_minimum_required(VERSION 3.2)

project(3d)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(${PROJECT_NAME} main.cpp)

add_library(curve lib/curve.h lib/curve.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE curve)

