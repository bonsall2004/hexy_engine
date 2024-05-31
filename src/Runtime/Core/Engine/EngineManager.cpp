/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include <iostream>
#include "EngineManager.hpp"

namespace hexy::runtime::core
{
  WindowManager* EngineManager::get_window_manager() const
  {
    return m_windowManager;
  }

  EngineManager::EngineManager()
  {
    m_windowManager = static_cast<WindowManager*>(malloc(sizeof(WindowManager)));
  }

  bool EngineManager::start()
  {
    if(!m_windowManager)
    {
      std::cerr << "m_windowManager is null, please init the window manager\n";
      return false;
    }
    window_manager_thread = std::thread(m_windowManager->begin());
    return true;
  }

  void EngineManager::cleanup()
  {
    if(window_manager_thread.joinable())
    {
      window_manager_thread.join();
    }

    free(m_windowManager);
  }

  const std::thread& EngineManager::get_window_manager_thread() const
  {
    return window_manager_thread;
  }

  bool EngineManager::init()
  {
    m_windowManager = new WindowManager(800, 600, "Hexy Runtime", true, true);
    return m_windowManager->init();
  }

  void EngineManager::join_active_threads()
  {
    if(window_manager_thread.joinable())
    {
      window_manager_thread.join();
    }
  }
} // hexy