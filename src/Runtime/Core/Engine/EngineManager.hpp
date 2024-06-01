/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <WindowManager/WindowManager.hpp>
#include <thread>

namespace hexy::runtime::core {

  class EngineManager {
    public:
      EngineManager();
      bool init();
      bool start();
      void cleanup();
      void join_active_threads();
      [[nodiscard]] WindowManager* get_window_manager() const;
      [[nodiscard]] const std::thread& get_window_manager_thread() const;

    private:
      WindowManager* m_windowManager;
      std::thread window_manager_thread;
  };

} // namespace hexy::runtime::core