/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "GLFW/glfw3.h"

#include <utility>
#include "ViewportCamera.hpp"

namespace hexy
{
  class WindowManager
  {
    public:
      WindowManager(int width, int height, std::string  window_name, bool resizable = true, bool vsync = true);
      ~WindowManager();

      void Begin();
      void SetVSync(bool enabled);


    protected:
      virtual void pre_render();
      virtual void render();
      virtual void post_render();

      virtual void key_event(int key, int scan_code, int action, int mods);

    private:
      static void error_callback(int error, const char* description);
      static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

      static void key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods);
      static void mouse_callback(GLFWwindow* window, double posx, double posy);
      static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

      static ViewportCamera* camera;

      int width;
      int height;
      std::string window_name;

      GLFWwindow* window{};

      static void InitGLFW();
      void CreateWindow(bool resizable);
  };
}