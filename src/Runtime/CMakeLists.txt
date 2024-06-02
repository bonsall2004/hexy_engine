cmake_minimum_required(VERSION 3.5)
project(hexy-runtime)

set(EXECUTABLE_NAME hexy-runtime)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../../binaries)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES main.cpp
    Core/WindowManager/WindowManager.cpp
    Core/WindowManager/WindowManager.hpp
    Core/Engine/EngineManager.cpp
    Core/Engine/EngineManager.hpp
    Core/Rendering/Renderer.hpp
    Core/Rendering/RenderManager.cpp
    Core/Rendering/RenderManager.hpp
    Core/Engine/EngineManager.cpp
    Core/Engine/EngineManager.hpp
    Core/Rendering/Shaders/ShaderManager.cpp
    Core/Rendering/Shaders/ShaderManager.hpp
    Core/ObjectLoader/ObjectLoader.cpp
    Core/ObjectLoader/ObjectLoader.hpp
    Core/Entities/ObjectBase.hpp
    Core/Components/ComponentManager.hpp
    Core/Components/ComponentManager.cpp
    Core/Entities/Object.hpp
    Core/Components/ComponentBase.hpp
    Core/Datatypes/Transform.hpp
    Core/Components/SceneComponent.cpp
    Core/Components/SceneComponent.hpp
    Core/Components/Meshes/StaticMeshComponent.hpp
    Core/Entities/Test.hpp
    Core/Datatypes/Transform.cpp)

include_directories("../../include" "./Core" "./Core/Entities" "./Core/Datatypes")

add_executable(${EXECUTABLE_NAME} ${SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(${EXECUTABLE_NAME} PRIVATE "../../deps/glfw/include" "../../deps/glfw/deps" "../../deps/glm/" "../../deps/glad/include")

target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${OPENGL_LIBRARIES} glfw glm glad)
