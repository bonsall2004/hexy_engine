/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include <glm/glm.hpp>

namespace hexy::runtime::core
{
  class HTransform
  {
    public:
      glm::vec3 position;
      glm::vec3 rotation;
      glm::vec3 scale;

      HTransform() : position(0.0f), rotation(0.0f), scale(1.0f)
      {
      }
      [[nodiscard]] glm::mat4 get_matrix() const;
  };
}
