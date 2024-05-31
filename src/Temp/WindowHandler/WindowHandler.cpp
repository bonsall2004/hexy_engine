/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include <iostream>
#include <utility>
#include "WindowHandler.hpp"

namespace hexy
{
  ViewportCamera* WindowManager::camera = nullptr;

  WindowManager::WindowManager(int width, int height, std::string  window_name, bool resizable, bool vsync)
    : width(width), height(height), window_name(std::move(window_name))
  {
    InitGLFW();
    CreateWindow(resizable);
    SetVSync(vsync);
  }

  WindowManager::~WindowManager()
  {
    if (window)
    {
      glfwDestroyWindow(window);
    }
    glfwTerminate();
  }

  void WindowManager::InitGLFW()
  {
    if (!glfwInit())
    {
      std::cerr << "Failed to initialize GLFW" << std::endl;
      exit(EXIT_FAILURE);
    }
    glfwSetErrorCallback(error_callback);
  }

  void WindowManager::CreateWindow(bool resizable)
  {
    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

    window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    if (!window)
    {
      std::cerr << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    camera = new ViewportCamera(window);
  }

  void WindowManager::SetVSync(bool enabled)
  {
    glfwSwapInterval(enabled ? 1 : 0);
  }

  void WindowManager::Begin()
  {


    while (!glfwWindowShouldClose(window))
    {
      camera->updateCamera();
      this->pre_render();
      this->render();
      this->post_render();

      glfwSwapBuffers(window);

      glfwPollEvents();
    }

  }

  void WindowManager::error_callback(int error, const char* description)
  {
    std::cerr << "Error: " << description << std::endl;
  }

  void WindowManager::key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
  {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

  void WindowManager::framebuffer_size_callback(GLFWwindow* window, int width, int height)
  {
    glViewport(0, 0, width, height);
  }

  void WindowManager::pre_render()
  {

  }

  void WindowManager::render()
  {

  }

  void WindowManager::post_render()
  {

  }
  void WindowManager::key_event(int key, int scan_code, int action, int mods)
  {

  }
  void WindowManager::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
  {
    camera->mouse_button_callback(window, button, action, mods);
  }
  void WindowManager::mouse_callback(GLFWwindow* window, double posx, double posy)
  {
    camera->mouse_callback(window, posx, posy);
  }
}
