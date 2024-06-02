/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <WindowManager/WindowManager.hpp>
#include <Object.hpp>
#include <ObjectLoader/ObjectLoader.hpp>
#include <thread>
#include <vector>
#include <memory>

namespace hexy::runtime::core {
  class EngineManager {
    public:
      EngineManager();
      bool init();
      bool start();
      void cleanup();
      void join_active_threads();
      [[nodiscard]] WindowManager* get_window_manager() const;
      const std::thread& get_window_manager_thread() const;

      void add_object(std::shared_ptr<ObjectBase> object);
      void remove_object(std::shared_ptr<ObjectBase> object);
      void clear_objects();

    private:
      WindowManager* m_windowManager;
      std::thread window_manager_thread;
      std::vector<std::shared_ptr<ObjectBase>> m_objects;
  };
}