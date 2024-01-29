cmake_minimum_required(VERSION 3.12)

project(3dcurves)

# Add the subdirectory for the library
add_subdirectory(src/lib)

# Add the executable and link with the library
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE curve)