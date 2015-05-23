#ifndef GAME_H
#define GAME_H

#include"board.h"

class Game{

public:
  Game();
  void move(Direction direction);
  void win();
  void gameover();
  void restart();
  int getscore();
  static const int winvalue=2048;

private:
  Board *board;
  bool youwin,gameisover;




};


#endif
