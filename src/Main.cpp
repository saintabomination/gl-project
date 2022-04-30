#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialise GLFW!" << std::endl;
    return -1;
  }

  glfwTerminate();
  return 0;
}
