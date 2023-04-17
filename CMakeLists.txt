cmake_minimum_required(VERSION 3.0)

project(simplecalc)

add_executable(${PROJECT_NAME} main.c)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} src)
