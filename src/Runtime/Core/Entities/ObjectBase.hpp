/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>
#include <Transform.hpp>

namespace hexy::runtime::core
{
  class ComponentBase;

  class ObjectBase
  {
    public:
      ObjectBase()
      {
        components = {};
      }
      virtual ~ObjectBase() = default;
      virtual void load(const std::string& path) = 0;
      virtual void draw(const glm::mat4& mvp) = 0;
      virtual void cleanup() = 0;

      std::shared_ptr<HTransform> transform;
      std::vector<std::shared_ptr<ComponentBase>> components;
  };
}
