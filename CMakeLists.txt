cmake_minimum_required(VERSION 3.15)
project(AoC2022)

#add_compile_definitions(INPUT_FILE_PATH="input")

add_subdirectory(src/)

set(CMAKE_C_STANDARD 11) # Requires C11 standard
set(CMAKE_CXX_STANDARD 20) # Requires C++20 standard

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For Kate, so that some headers are found by the LSP

add_library(${PROJECT_NAME} INTERFACE)
target_link_libraries(${PROJECT_NAME} INTERFACE Day1 Day1h Day2)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
