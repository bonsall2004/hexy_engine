/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <glm/glm.hpp>
#include <string>

namespace hexy::runtime::core
{
  class ComponentBase
  {
    public:
      virtual ~ComponentBase() = default;
      virtual void load() = 0;
      virtual void draw() = 0;
      virtual void cleanup() = 0;
  };
}