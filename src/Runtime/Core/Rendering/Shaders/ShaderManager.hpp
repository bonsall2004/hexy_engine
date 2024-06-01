/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <vector>
#include <ObjectLoader/ObjectLoader.hpp>

namespace hexy::rendering {

  class ShaderManager {
    public:
      ShaderManager();
      ~ShaderManager();
      void init();
      [[maybe_unused]] void load_object(const std::string& filename);
      void render(const glm::mat4& mvp);
      void cleanup();

    private:
      GLuint program;
      GLuint vertex_shader;
      GLuint fragment_shader;
      GLuint vertex_array;
      GLuint vertex_buffer;
      GLuint index_buffer;
      GLint mvp_location;
      ObjectLoader object_loader;

      static void check_shader_compile_error(GLuint shader, const std::string& type);
  };

} // namespace hexy::rendering