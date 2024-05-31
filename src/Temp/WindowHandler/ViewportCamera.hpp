/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */
#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "GLFW/glfw3.h"

namespace hexy
{
  class ViewportCamera
  {
    public:
      explicit ViewportCamera(GLFWwindow* window);

      [[nodiscard]] glm::mat4 getViewMatrix() const;
      [[nodiscard]] glm::mat4 getProjectionMatrix(float screenWidth, float screenHeight) const;

      void updateCamera();
      void mouse_callback(GLFWwindow* _window, double xpos, double ypos);
      void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    private:
      glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
      glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
      glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

      float cameraSpeed = 0.05f;
      float yaw = -90.0f;
      float pitch = 0.0f;
      float fov = 45.0f;
      float sensitivity = 0.1f;

      bool firstMouse = true;
      bool rightMouseButtonPressed = false;
      double lastX = 0.0;
      double lastY = 0.0;

      GLFWwindow* window;
  };
}