/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include "GLFW/glfw3.h"
#include <string>
#include <cstdint>
#include <thread>

namespace hexy::runtime::core
{
  class WindowManager
  {
    public:
      explicit WindowManager(uint16_t width = 800, uint16_t height = 600, std::string window_name = "Untitled", bool resize = true, bool vsync = true);

      bool init();
      std::thread begin();

      [[nodiscard]] GLFWwindow* get_window() const;
      [[nodiscard]] bool is_resizable() const;
      [[nodiscard]] bool is_vsync() const;

      void cleanup();

      void set_resizable(bool resizable);
      void set_vsync(bool vsync);
      void set_exit_callback(void(*callback)());

    protected:
      static void default_error_callback(int error_code, const char* description);
      static void default_framebuffer_size_callback(GLFWwindow* window, int width, int height);

      virtual void pre_render();
      virtual void render();
      virtual void post_render();

      static void key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods);

      bool create_window();

    private:
      std::string title;

      uint16_t width;
      uint16_t height;

      bool resizable = true;
      bool vsync = true;

      void(* exit_callback)();

      GLFWwindow* window;

  };
}