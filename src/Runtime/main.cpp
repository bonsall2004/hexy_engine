#include <Engine/EngineManager.hpp>
#include <ObjectLoader/ObjectLoader.hpp> // Include ObjectLoader header
#include <Test.hpp>

using namespace hexy::runtime::core;

int main() {
  EngineManager engineManager;

  if (!engineManager.init()) {
    return -1;
  }

  // Create and add objects

  engineManager.add_object(std::make_shared<TestOBJ>());

  if (!engineManager.start()) {
    return -1;
  }

  engineManager.join_active_threads();
  engineManager.cleanup();

  return 0;
}
