/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "ShaderManager.hpp"
#include <iostream>

namespace hexy::rendering
{

  ShaderManager::ShaderManager() : vertex_shader(glCreateShader(GL_VERTEX_SHADER)), fragment_shader(glCreateShader(GL_FRAGMENT_SHADER)), program(glCreateProgram())
  {
  }

  ShaderManager::~ShaderManager()
  {
    cleanup();
  }

  void ShaderManager::init()
  {
    const char* vertex_shader_text = R"(
        #version 460 core
        layout(location = 0) in vec3 aPos;
        uniform mat4 MVP;
        void main() {
            gl_Position = MVP * vec4(aPos, 1.0);
        }
    )";
    const char* fragment_shader_text = R"(
        #version 460 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0, 0.45, 1.0, 1.0);
        }
    )";

    glShaderSource(vertex_shader, 1, &vertex_shader_text, nullptr);
    glCompileShader(vertex_shader);
    check_shader_compile_error(vertex_shader, "VERTEX");

    glShaderSource(fragment_shader, 1, &fragment_shader_text, nullptr);
    glCompileShader(fragment_shader);
    check_shader_compile_error(fragment_shader, "FRAGMENT");

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
      char infoLog[512];
      glGetProgramInfoLog(program, 512, nullptr, infoLog);
      std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    mvp_location = glGetUniformLocation(program, "MVP");
  }

  [[maybe_unused]] void ShaderManager::load_object(const std::string& filename)
  {
    if(!object_loader.load(filename))
    {
      std::cerr << "Failed to load object: " << filename << std::endl;
      return;
    }

    glGenBuffers(1, &vertex_buffer);
    glGenBuffers(1, &index_buffer);
    glGenVertexArrays(1, &vertex_array);

    glBindVertexArray(vertex_array);

    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, object_loader.get_vertices()
      .size() * sizeof(glm::vec3), object_loader.get_vertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, object_loader.get_indices()
      .size() * sizeof(unsigned int), object_loader.get_indices().data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);

    glUseProgram(program);
  }

  void ShaderManager::render(const glm::mat4& mvp)
  {
    glUseProgram(program);
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvp[0][0]);

    glBindVertexArray(vertex_array);
    glDrawElements(GL_TRIANGLES, object_loader.get_indices().size(), GL_UNSIGNED_INT, 0);
  }

  void ShaderManager::cleanup()
  {
    glDeleteBuffers(1, &vertex_buffer);
    glDeleteBuffers(1, &index_buffer);
    glDeleteVertexArrays(1, &vertex_array);
    glDeleteProgram(program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
  }

  void ShaderManager::check_shader_compile_error(GLuint shader, const std::string& type)
  {
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char infoLog[512];
      glGetShaderInfoLog(shader, 512, nullptr, infoLog);
      std::cerr << "ERROR::SHADER::" << type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
  }

} // namespace hexy::rendering