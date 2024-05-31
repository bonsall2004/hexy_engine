/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "WindowManager.hpp"
#include "glad/glad.h"
#include <iostream>

namespace hexy::runtime::core
{
  WindowManager::WindowManager(uint16_t width, uint16_t height, std::string window_name, bool resize, bool vsync) : width(width), height(height), title(std::move(window_name)), resizable(resize), vsync(vsync)
  {
  }

  bool WindowManager::init()
  {
    if(!glfwInit())
    {
      std::cerr << "Uh oh, GLFW Failed to initialize\n";
      return false;
    }
    glfwSetErrorCallback(default_error_callback);

    return create_window();
  }

  GLFWwindow* WindowManager::get_window() const
  {
    return window;
  }

  bool WindowManager::create_window()
  {
    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(!window)
    {
      std::cerr << "Uh ohh, Failed to create a GLFW window\n";
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window, key_callback);

    glfwSetFramebufferSizeCallback(window, default_framebuffer_size_callback);

    glfwSwapInterval(vsync ? 1 : 0);
    return true;
  }

  void WindowManager::default_error_callback(int error_code, const char* description)
  {

  }

  void WindowManager::default_framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    glViewport(0, 0, width, height);
  }

  void WindowManager::post_render()
  {

  }

  void WindowManager::render()
  {

  }

  void WindowManager::pre_render()
  {

  }

  std::thread WindowManager::begin()
  {

    while(!glfwWindowShouldClose(window))
    {
      this->pre_render();

      glfwPollEvents();

      this->render();

      glfwSwapBuffers(window);

      this->post_render();
    }

    glfwTerminate();

    if(exit_callback)
    {
      exit_callback();
    }

    return {};
  }

  void WindowManager::key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
  {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

  bool WindowManager::is_resizable() const
  {
    return resizable;
  }

  void WindowManager::set_resizable(bool _resizable)
  {
    WindowManager::resizable = _resizable;
  }

  bool WindowManager::is_vsync() const
  {
    return vsync;
  }

  void WindowManager::set_vsync(bool _vsync)
  {
    WindowManager::vsync = _vsync;
  }

  void WindowManager::cleanup()
  {
    glfwTerminate();
    free(window);
  }
  void WindowManager::set_exit_callback(void(*callback)())
  {
    exit_callback = callback;
  }

}