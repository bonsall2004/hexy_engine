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

    protected:
      void OnObjectLoad() override
      {
        std::cout << "Loading Test OBJECT\n";
      }
  };
}