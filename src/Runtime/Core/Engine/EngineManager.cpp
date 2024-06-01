/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "EngineManager.hpp"
#include <iostream>

namespace hexy::runtime::core {

  EngineManager::EngineManager() : m_windowManager(nullptr) {}

  bool EngineManager::init() {
    m_windowManager = new WindowManager(800, 600, "Hexy Runtime", true, true);
    return m_windowManager->init();
  }

  bool EngineManager::start() {
    if (!m_windowManager) {
      std::cerr << "m_windowManager is null, please init the window manager\n";
      return false;
    }
    window_manager_thread = m_windowManager->begin();
    return true;
  }

  void EngineManager::cleanup() {
    if (window_manager_thread.joinable()) {
      window_manager_thread.join();
    }
    delete m_windowManager;
  }

  void EngineManager::join_active_threads() {
    if (window_manager_thread.joinable()) {
      window_manager_thread.join();
    }
  }

  WindowManager* EngineManager::get_window_manager() const {
    return m_windowManager;
  }

  const std::thread& EngineManager::get_window_manager_thread() const {
    return window_manager_thread;
  }

} // namespace hexy::runtime::core
