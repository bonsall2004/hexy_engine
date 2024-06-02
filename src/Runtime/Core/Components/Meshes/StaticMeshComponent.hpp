/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "../ComponentBase.hpp"
#include <ObjectLoader/ObjectLoader.hpp>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

namespace hexy::runtime::core { // this file is a shit hole and im gunna fix it when i can be fucked
  class StaticMeshComponent : public ComponentBase {
    public:
      void load(const std::string& path) override {
        vertices = {
          { -0.5f, -0.5f, 0.0f },
          { 0.5f, -0.5f, 0.0f },
          { 0.0f, 0.5f, 0.0f }
        };
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
      }

      void draw(const glm::mat4& mvp) override {
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        glBindVertexArray(0);
      }

      void cleanup() override {
        glDeleteVertexArrays(1, &vao);
        glDeleteBuffers(1, &vbo);
      }

    private:
      std::vector<glm::vec3> vertices;
      GLuint vao, vbo;
  };
}