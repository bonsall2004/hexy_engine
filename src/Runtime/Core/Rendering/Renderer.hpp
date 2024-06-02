/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <glm/glm.hpp>

namespace hexy::rendering
{

  class Renderer
  {
    public:
      virtual ~Renderer() = default;
      virtual void init() = 0;
      virtual void render(const glm::mat4& mvp) = 0;
      virtual void cleanup() = 0;
  };

}