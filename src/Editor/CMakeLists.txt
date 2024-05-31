cmake_minimum_required(VERSION 3.5)
project(hexy-editor)

set(EXECUTABLE_NAME hexy-editor)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../binaries)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES ../Temp/entry.cpp ../Temp/WindowHandler/WindowHandler.cpp ../Temp/WindowHandler/ViewportCamera.cpp)
set(HEADERS
    ../Temp/temp_shader.cpp)

add_executable(${EXECUTABLE_NAME} ${SOURCES} ${HEADERS})

find_package(OpenGL REQUIRED)

target_include_directories(${EXECUTABLE_NAME} PRIVATE "../../deps/glfw/include" "../../deps/glm/")

target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${OPENGL_LIBRARIES} glfw glm)
