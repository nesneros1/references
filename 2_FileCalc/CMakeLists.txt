cmake_minimum_required(VERSION 3.0)

project(filecalc)

set (SOURCES
    src/main.c
)

add_executable(filecalc ${SOURCES})

target_include_directories(filecalc PRIVATE ~/calculator_project/1_SimpleCalc/include)



