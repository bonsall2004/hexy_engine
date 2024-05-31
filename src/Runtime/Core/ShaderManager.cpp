/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "ShaderManager.hpp"
#include "../../../deps/glfw/deps/linmath.h"
#include <glfw/glfw3.h>
#include <iostream>

typedef struct Vertex
{
  vec2 pos;
  vec3 col;
} Vertex;

static const Vertex vertices[3] =
  {
    { { -0.6f, -0.4f }, { 1.f, 0.f, 0.f } },
    { {  0.6f, -0.4f }, { 0.f, 1.f, 0.f } },
    { {   0.f,  0.6f }, { 0.f, 0.f, 1.f } }
  };

static const char* vertex_shader_text =
  "#version 330\n"
  "uniform mat4 MVP;\n"
  "in vec3 vCol;\n"
  "in vec2 vPos;\n"
  "out vec3 color;\n"
  "void main()\n"
  "{\n"
  "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
  "    color = vCol;\n"
  "}\n";

static const char* fragment_shader_text =
  "#version 330\n"
  "in vec3 color;\n"
  "out vec4 fragment;\n"
  "void main()\n"
  "{\n"
  "    fragment = vec4(color, 1.0);\n"
  "}\n";



namespace hexy::runtime::core
{

  rendering::ShaderManager::ShaderManager() :
  vertex_shader(glCreateShader(GL_VERTEX_SHADER)),
  fragment_shader(glCreateShader(GL_FRAGMENT_SHADER)),
  program(glCreateProgram()) {}

  void rendering::ShaderManager::init()
  {
    glGenBuffers(1, &vertex_buffer);
    glGenVertexArrays(1, &vertex_arrays);

    glBindVertexArray(vertex_arrays);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    GLint success;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char info[512];
      glGetShaderInfoLog(vertex_shader, 512, NULL, info);
      std::cout << info << std::endl;
    }

    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char info[512];
      glGetShaderInfoLog(fragment_shader, 512, NULL, info);
      std::cout << info << std::endl;
    }

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    mvp_location = glGetUniformLocation(program, "MVP");
    vpos_location = glGetUniformLocation(program, "vPos");
    vcol_location = glGetUniformLocation(program, "vCol");

    glBindVertexArray(vertex_arrays);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, col));

    glBindVertexArray(0);

    glUseProgram(program);
  }

  GLint rendering::ShaderManager::get_mvp_location() const
  {
    return mvp_location;
  }
  GLint rendering::ShaderManager::get_vpos_location() const
  {
    return vpos_location;
  }
  GLint rendering::ShaderManager::get_vcol_location() const
  {
    return vcol_location;
  }
  const GLuint rendering::ShaderManager::get_program() const
  {
    return program;
  }
  GLuint& rendering::ShaderManager::get_vertex_arrays()
  {
    return vertex_arrays;
  }
  void rendering::ShaderManager::cleanup()
  {
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteVertexArrays(1, &vertex_arrays);
    glDeleteProgram(program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
  }

} // hexy