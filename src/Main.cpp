#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

const char* vertexShaderSource =
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.f);\n"
  "}\0";

const char* fragmentShaderSource =
  "#version 330 core\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  " FragColor = vec4(1.f, 0.f, 0.f, 1.f);\n"
  "}\0";

int main()
{
  // GLFW Intialisation

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

  // GLEW Intialisation

  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cout << "Failed to initialise GLEW!\n";
    std::cout << "Error: " << glewGetErrorString(err) << '\n';
    return -1;
  }

  float vertices[] = {
    -1.f, -1.f, 0.f,
    1.f, -1.f, 0.f,
    0.f, 1.f, 0.f
  };

  // VBO

  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  // Creating Shaders

  GLuint vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int shaderSuccess;
  char infoLog[512];

  // GLSL Error Checking

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderSuccess);
  if (!shaderSuccess)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "Shader compilation failed!\n" << infoLog << '\n';
  }

  GLuint fragmentShader;
  vertexShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &shaderSuccess);
  if (!shaderSuccess)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "Shader compilation failed!\n" << infoLog << '\n';
  }

  // Linking Shaders to Shader Program

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
      0,
      3,
      GL_FLOAT,
      GL_FALSE,
      0,
      (void*)0
    );
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
  }

  glfwTerminate();
  return 0;
}
