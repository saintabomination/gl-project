#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

int main()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialise GLFW!\n";
    return -1;
  }

  // Window Hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window;
  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GLFW", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to initialise GLFW Window!\n";
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cout << "Failed to initialise GLEW!\n";
    std::cout << "Error: " << glewGetErrorString(err) << '\n';
    return -1;
  }

  glfwTerminate();
  return 0;
}
