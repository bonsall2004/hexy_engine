/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include <vector>
#include <memory>
#include "../Rendering/Renderer.hpp"
#include <ObjectBase.hpp>

namespace hexy::runtime::core
{
  class ComponentManager
  {
    public:
      void add_renderer(std::shared_ptr<hexy::rendering::Renderer> renderer);
      void add_object(std::shared_ptr<ObjectBase> object);
      void render_all(const glm::mat4& mvp);
      void cleanup_all();

    private:
      std::vector<std::shared_ptr<hexy::rendering::Renderer>> renderers;
      std::vector<std::shared_ptr<ObjectBase>> objects;
  };
}