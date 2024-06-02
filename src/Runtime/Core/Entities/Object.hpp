/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "ObjectBase.hpp"

namespace hexy::runtime::core {
  class Object : public ObjectBase {
    protected:
      void load(const std::string& path) override {
        for (auto& component : components) {
          component->load(path);
        }
      }

      void draw(const glm::mat4& mvp) override {
        for (auto& component : components) {
          component->draw(mvp);
        }
      }

      void cleanup() override {
        for (auto& component : components) {
          component->cleanup();
        }
      }

      virtual void OnObjectLoad() = 0;
  };
}