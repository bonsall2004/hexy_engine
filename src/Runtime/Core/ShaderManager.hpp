/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <unordered_map>
#include <string>
#include "glad/glad.h"

namespace hexy::runtime::core::rendering
{
  class ShaderManager
  {
    public:
      ShaderManager();
//
//      void create_vertex_shader(const std::string& shader_code);
//      void create_fragment_shader(const std::string& shader_code);
//      int create_shader(const std::string& shader_code, int shader_type);
//      void create_uniform(const std::string& uniform_name);
//      void create_material_uniform(const std::string& uniform_name);
//      void create_directional_light_uniform(const std::string& uniform_name);
//      void create_point_light_uniform(const std::string& uniform_name);
//      void create_spotlight_uniform(const std::string& uniform_name);
//      void set_uniform(const std::string& uniform_name, bool value);




    protected:

    private:
      GLuint vertex_buffer;
      const GLuint vertex_shader;
      const GLuint fragment_shader;
      const GLuint program;
      const std::unordered_map<std::string, int> m_uniforms;
  };
} // hexy
