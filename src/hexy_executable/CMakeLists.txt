cmake_minimum_required(VERSION 3.5)
project(hexy)

set(EXECUTABLE_NAME hexy)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../binaries)
set(CMAKE_CXX_STANDARD 23)

set(SOURCES entry.cpp)
set(COMPILED_HEADERS)

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${COMPILED_HEADERS})