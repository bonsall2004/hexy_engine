/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "../ComponentBase.hpp"
#include <ObjectParser/ObjectParser.hpp>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

// this file is a shithole and im gunna fix it when i can be fucked
namespace hexy::runtime::core
{
class StaticMeshComponent : public ComponentBase
  {
    public:
      void load() override;
      void draw() override;
      void cleanup() override;

      std::string obj_path = "armadillo.obj";

    private:
      std::vector<glm::vec3> vertices;
      GLuint vao, vbo;
  };
}