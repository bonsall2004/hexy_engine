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
#include "ComponentBase.hpp"

namespace hexy::runtime::core {
  class ObjectBase {
    public:

      virtual ~ObjectBase() = default;
      void add_component(std::shared_ptr<ComponentBase> component) {
        components.push_back(component);
      }

      virtual void cleanup() = 0;
      virtual void load(const std::string& path) = 0;
      virtual void draw(const glm::mat4& mvp) = 0;

    protected:
      std::vector<std::shared_ptr<ComponentBase>> components;
  };
}