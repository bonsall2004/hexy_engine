/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "Object.hpp"
#include <Components/Meshes/StaticMeshComponent.hpp>

namespace hexy::runtime::core {
  class TestOBJ : public Object {
    protected:
      void OnObjectLoad() override
      {
        auto StaticMesh = std::make_shared<StaticMeshComponent>();
        this->add_component(StaticMesh);
      }
  };
}