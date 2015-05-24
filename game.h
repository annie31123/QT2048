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
  void giverandtwo();
  int getvalue(int i,int j);
  int getscore();
  static const int winvalue=2048;
  bool youwin,gameisover;

private:
  Board *board;





};


#endif
