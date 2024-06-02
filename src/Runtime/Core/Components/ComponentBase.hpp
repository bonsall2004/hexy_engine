/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <glm/glm.hpp>
#include <string>

namespace hexy::runtime::core {
  class ComponentBase {
    public:
      virtual ~ComponentBase() = default;
      virtual void load(const std::string& path) = 0;
      virtual void draw(const glm::mat4& mvp) = 0;
      virtual void cleanup() = 0;
  };
}