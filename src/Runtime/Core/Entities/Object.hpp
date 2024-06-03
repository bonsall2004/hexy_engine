/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include "ObjectBase.hpp"
#include <Components/ComponentBase.hpp>
#include <Components/Meshes/StaticMeshComponent.hpp>

namespace hexy::runtime::core
{
  class Object : public ObjectBase
  {
    public:
      Object()
      {
        std::cout << "Constructing Test OBJECT\n";
        components.push_back(std::make_shared<StaticMeshComponent>());
      }

      ~Object() override
      {

      }
      void draw(const glm::mat4& mvp) override
      {
        for(const auto& component : components)
        {
          component->draw();
        }
      }
      void cleanup() override
      {
        for(const auto& component : components)
        {
          component->cleanup();
        }
      }

      void load() override
      {
        for(const auto& component : components)
        {
          component->load();
        }
      }
      std::shared_ptr<HTransform> transform;
      std::vector<std::shared_ptr<ComponentBase>> components;

    protected:
      virtual void OnObjectLoad() = 0;
  };
}