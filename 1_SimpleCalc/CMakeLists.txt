cmake_minimum_required(VERSION 3.0)

project(simplecalc)

set (SOURCES
    src/main.c
    src/operations.c
)

add_executable(simplecalc ${SOURCES})

target_include_directories(simplecalc PRIVATE ${PROJECT_SOURCE_DIR}/include)



