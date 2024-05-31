/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "Core/WindowManager/WindowManager.hpp"
#include "Core/Engine/EngineManager.hpp"

using namespace hexy::runtime;


int main()
{
  auto* EngineManager = new core::EngineManager();
  EngineManager->init();
  EngineManager->start();
  EngineManager->join_active_threads();
  free(EngineManager);
  return 0;
}