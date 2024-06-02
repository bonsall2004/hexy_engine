/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#include <iostream>
#include <memory>
#include "Engine/EngineManager.hpp"
#include <Test.hpp>
#include <ObjectBase.hpp>

using namespace hexy::runtime::core;

int main()
{
  hexy::runtime::core::EngineManager engineManager;

  if(!engineManager.init())
  {
    std::cerr << "Failed to initialize engine" << std::endl;
    return -1;
  }

  auto testObj = std::make_shared<TestOBJ>();
  testObj->load("armadillo.obj");
  testObj->transform = std::make_shared<hexy::runtime::core::HTransform>();
  testObj->transform->position = glm::vec3(0.0f, 0.0f, -5.0f);
  engineManager.add_object(testObj);

  if(!engineManager.start())
  {
    std::cerr << "Failed to start engine" << std::endl;
    return -1;
  }

  engineManager.join_active_threads();
  engineManager.cleanup();

  return 0;
}
