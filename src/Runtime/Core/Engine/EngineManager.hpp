/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <chrono>
#include <thread>
#include "../WindowManager/WindowManager.hpp"

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

      [[nodiscard]] WindowManager* get_window_manager() const;

    protected:

    private:
      WindowManager* m_windowManager;
      std::thread window_manager_thread;
    public:
      const std::thread& get_window_manager_thread() const;
  };
} // hexy
