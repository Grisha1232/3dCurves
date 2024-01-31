cmake_minimum_required(VERSION 3.2)

project(3d)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ../)


add_library(curve SHARED lib/curve.cpp)

target_include_directories(curve PUBLIC lib)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE curve)

