cmake_minimum_required(VERSION 3.20)
project(glad)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES ./src/glad.c)

add_library(glad ${SOURCES})
target_include_directories(glad PUBLIC ./include)