#ifndef GAME_H
#define GAME_H

#include "../Headers.h"

class Game
{
  private:
    GLFWwindow* window;

    // Intialisers
    void initWindow();

  public:
    // Constructor
    Game();

  private:
    void run();
};

#endif // GAME_H
