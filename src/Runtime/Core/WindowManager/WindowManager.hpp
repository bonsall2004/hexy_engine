/*
 * hexy_engine
 * Author: bonsall2004
 * Description: 
 */
#pragma once
#include <string>
#include <thread>
#include <Rendering/Shaders/ShaderManager.hpp>
#include <Components/ComponentManager.hpp>
#include <ObjectBase.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

namespace hexy::runtime::core
{
  class WindowManager
  {
    public:
      WindowManager(uint16_t width, uint16_t height, std::string window_name, bool resize, bool vsync);

      bool init();
      std::thread begin();
      void cleanup();

      [[nodiscard]] bool is_resizable() const;
      void set_resizable(bool _resizable);
      [[nodiscard]] bool is_vsync() const;
      void set_vsync(bool _vsync);
      void set_exit_callback(void(* callback)());

      ComponentManager componentManager;
      std::vector<std::shared_ptr<ObjectBase>> objects;

    private:
      bool create_window();

      void render();
      void pre_render();
      void post_render();

      static void key_callback(GLFWwindow* window, int key, int scan_code, int action, int mods);
      static void default_error_callback(int error_code, const char* description);
      static void default_framebuffer_size_callback(GLFWwindow* window, int width, int height);

      uint16_t width;
      uint16_t height;
      std::string title;
      bool resizable;
      bool vsync;
      GLFWwindow* window;
      void (* exit_callback)() = nullptr;
      glm::mat4 mvp;
  };
}
