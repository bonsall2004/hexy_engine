/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#include "WindowManager.hpp"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

namespace hexy::runtime::core
{

  WindowManager::WindowManager(uint16_t width, uint16_t height, std::string window_name, bool resize, bool vsync) : width(width), height(height), title(std::move(window_name)), resizable(resize), vsync(vsync), window(nullptr)
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
    bool success = create_window();

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cerr << "Failed to initialize GLAD\n";
      return false;
    }

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    auto model = glm::mat4(1.0f);
    mvp = projection * view * model;

    return success;
  }

  bool WindowManager::create_window()
  {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, resizable ? GLFW_TRUE : GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(!window)
    {
      std::cerr << "Uh ohh, Failed to create a GLFW window\n";
      glfwTerminate();
      return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, default_framebuffer_size_callback);
    glfwSwapInterval(vsync ? 1 : 0);
    return true;
  }

  void WindowManager::default_error_callback(int error_code, const char* description)
  {
    std::cerr << "GLFW ERROR " << error_code << ": " << description << std::endl;
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    componentManager.render_all(mvp);
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

    componentManager.cleanup_all();

    glfwTerminate();

    if(exit_callback)
    {
      exit_callback();
    }
    return {};
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
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  void WindowManager::set_exit_callback(void(* callback)())
  {
    exit_callback = callback;
  }

  void WindowManager::key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods)
  {
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

} // namespace hexy::runtime::core