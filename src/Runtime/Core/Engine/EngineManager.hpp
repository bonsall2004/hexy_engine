/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include <memory>
#include <vector>
#include "WindowManager/WindowManager.hpp"
#include "ObjectBase.hpp"

namespace hexy::runtime::core
{
  class EngineManager
  {
    public:
      EngineManager();
      bool init();
      bool start();
      void cleanup();
      void join_active_threads();
      void add_object(std::shared_ptr<ObjectBase> object);
      [[nodiscard]] WindowManager* get_window_manager() const;
      [[nodiscard]] const std::thread& get_window_manager_thread() const;
      [[nodiscard]] WindowManager* get_m_window_manager() const;
      [[nodiscard]] ComponentManager* get_m_component_manager() const;

    private:
      WindowManager* m_windowManager;
      ComponentManager* m_componentManager;
      ObjectLoader* m_objectLoader;


      std::thread window_manager_thread;
      std::vector<std::shared_ptr<ObjectBase>> objects;
  };
}
