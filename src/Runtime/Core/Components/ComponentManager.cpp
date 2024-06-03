/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "ComponentManager.hpp"

namespace hexy::runtime::core
{

  void ComponentManager::add_renderer(std::shared_ptr<hexy::rendering::Renderer> renderer)
  {
    renderers.push_back(renderer);
    renderer->init();
  }

  void ComponentManager::add_object(std::shared_ptr<ObjectBase> object)
  {
    objects.push_back(object);
  }

  void ComponentManager::render_all(const glm::mat4& mvp)
  {
    for(auto& renderer : renderers)
    {
      renderer->render(mvp);
    }
    for(auto& object : objects)
    {
      object->draw(mvp);
    }
  }

  void ComponentManager::cleanup_all()
  {
    for(auto& renderer : renderers)
    {
      renderer->cleanup();
    }
    for(auto& object : objects)
    {
      object->cleanup();
    }
  }
}
