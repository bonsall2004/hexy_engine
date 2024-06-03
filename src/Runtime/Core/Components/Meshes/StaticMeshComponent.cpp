/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "../ComponentBase.hpp"
#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <iostream>
#include <memory>
#include "StaticMeshComponent.hpp"

// this file is a shithole and im gunna fix it when i can be fucked
using namespace hexy::runtime::core;

void StaticMeshComponent::load() {
  auto parser = std::make_unique<ObjectParser>();
  parser->load(obj_path);
  vertices = parser->get_vertices();

  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);

  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  std::cout << "Loaded mesh successfully." << std::endl;
}

void StaticMeshComponent::draw() {
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, vertices.size());
  glBindVertexArray(0);
}

void StaticMeshComponent::cleanup()
{
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &vbo);
}

