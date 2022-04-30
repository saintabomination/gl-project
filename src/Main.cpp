#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialise GLFW!\n";
    return -1;
  }

  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cout << "Failed to initialise GLEW!\n";
    std::cout << "Error: " << glewGetErrorString(err) << '\n';
  }

  glfwTerminate();
  return 0;
}
