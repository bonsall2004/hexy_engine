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
    clear_objects();
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

  void EngineManager::add_object(std::shared_ptr<ObjectBase> object) {
    m_objects.push_back(object);
  }

  void EngineManager::remove_object(std::shared_ptr<ObjectBase> object) {
    m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
  }

  void EngineManager::clear_objects() {
    for (auto& object : m_objects) {
      object->cleanup();
    }
    m_objects.clear();
  }
}