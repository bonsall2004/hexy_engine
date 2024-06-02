/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "Object.hpp"
#include <Components/Meshes/StaticMeshComponent.hpp>
#include <iostream>

namespace hexy::runtime::core
{
  class TestOBJ : public Object
  {
    public:
      TestOBJ()
      {
        std::cout << "Constructing Test OBJECT\n";
      }

      ~TestOBJ()
      {

      }
      void load(const std::string& path) override
      {

      }
      void draw(const glm::mat4& mvp) override
      {

      }
      void cleanup() override
      {

      }

    protected:
      void OnObjectLoad() override
      {
        std::cout << "Loading Test OBJECT\n";
      }
  };
}