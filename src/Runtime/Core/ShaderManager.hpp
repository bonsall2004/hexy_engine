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
      void init();
      GLint get_mvp_location() const;
      GLint get_vpos_location() const;
      GLint get_vcol_location() const;
      const GLuint get_program() const;
      GLuint& get_vertex_arrays();
      void cleanup();

    protected:

    private:

      GLuint vertex_buffer;
      GLuint vertex_arrays;
      const GLuint vertex_shader;
      const GLuint fragment_shader;
      const GLuint program;
      GLint mvp_location;
      GLint vpos_location;
      GLint vcol_location;
      const std::unordered_map<std::string, int> m_uniforms;
  };
} // hexy
