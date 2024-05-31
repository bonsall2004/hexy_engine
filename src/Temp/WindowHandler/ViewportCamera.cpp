/*
 * hexy_engine
 * Author: bonsall2004
 * Description:
 */

#include "ViewportCamera.hpp"

namespace hexy
{
  ViewportCamera::ViewportCamera(GLFWwindow* window) : window(window) {}

  void ViewportCamera::updateCamera()
  {
    if (rightMouseButtonPressed)
    {
      double xpos, ypos;
      glfwGetCursorPos(window, &xpos, &ypos);

      if (firstMouse)
      {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
      }

      float xoffset = xpos - lastX;
      float yoffset = lastY - ypos;
      lastX = xpos;
      lastY = ypos;

      xoffset *= sensitivity;
      yoffset *= sensitivity;

      yaw += xoffset;
      pitch += yoffset;

      if (pitch > 89.0f)
        pitch = 89.0f;
      if (pitch < -89.0f)
        pitch = -89.0f;

      glm::vec3 front;
      front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
      front.y = sin(glm::radians(pitch));
      front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
      cameraFront = glm::normalize(front);
    }

    // Move camera
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      cameraPosition += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      cameraPosition -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
  }

  void ViewportCamera::mouse_callback(GLFWwindow* _window, double xpos, double ypos)
  {
    if (rightMouseButtonPressed)
    {
      if (firstMouse)
      {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
      }

      float xoffset = xpos - lastX;
      float yoffset = lastY - ypos;
      lastX = xpos;
      lastY = ypos;

      xoffset *= sensitivity;
      yoffset *= sensitivity;

      yaw += xoffset;
      pitch += yoffset;

      // Constrain pitch
      if (pitch > 89.0f)
        pitch = 89.0f;
      if (pitch < -89.0f)
        pitch = -89.0f;

      glm::vec3 front;
      front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
      front.y = sin(glm::radians(pitch));
      front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
      cameraFront = glm::normalize(front);
    }
  }

  void ViewportCamera::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
  {
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
      if (action == GLFW_PRESS)
        rightMouseButtonPressed = true;
      else if (action == GLFW_RELEASE)
      {
        rightMouseButtonPressed = false;
        firstMouse = true;
      }
    }
  }

  glm::mat4 ViewportCamera::getViewMatrix() const
  {
    return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
  }

  glm::mat4 ViewportCamera::getProjectionMatrix(float screenWidth, float screenHeight) const
  {
    return glm::perspective(glm::radians(fov), screenWidth / screenHeight, 0.1f, 100.0f);
  }
}