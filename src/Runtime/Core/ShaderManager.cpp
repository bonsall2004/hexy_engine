/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "ShaderManager.hpp"
#include "../../../deps/glfw/deps/linmath.h"
#include <glfw/glfw3.h>
#include <hash_map>

typedef struct Vertex
{
  vec3 pos;
  vec3 normal;
  vec2 tex;
} Vertex;

static const Vertex vertices[3] =
  {
    { { -0.6f, -0.4f }, { 1.f, 0.f, 0.f } },
    { {  0.6f, -0.4f }, { 0.f, 1.f, 0.f } },
    { {   0.f,  0.6f }, { 0.f, 0.f, 1.f } }
  };

namespace hexy::runtime::core
{

  rendering::ShaderManager::ShaderManager() : vertex_shader(glCreateShader(GL_VERTEX_SHADER)), fragment_shader(glCreateShader(GL_FRAGMENT_SHADER)), program(glCreateProgram())
  {
    glCreateBuffers(1, &vertex_buffer);
    glNamedBufferStorage(vertex_buffer, sizeof(vertices), vertices, 0);

    
  }
} // hexy