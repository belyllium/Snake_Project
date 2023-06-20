#include "SnakeGame.h"

int main()
{

  SnakeGame StartGame;
  while(StartGame.stage<=4)
  {
    beep();
    StartGame.Start(StartGame.stage);
    if(StartGame.death == TRUE)
    {
      return 0;
    }
  }
  return 0;
}