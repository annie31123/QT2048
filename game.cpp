#include "game.h"
#include <iostream>
using namespace std;

Game::Game(){
  restart();
}

void Game::restart(){
  board->score=0;
  youwin=false;
  gameisover=false;
}

void Game::giverandtwo(){
    board->makerand2();
}

int Game::getvalue(int i,int j){
    return board->getarrayvalue(i,j);
}


void Game::move(Direction direction){
  board->move(direction);
  board->makerand2();

  for(int i=0;i<board->getsize();i++)
    for(int j=0;j<board->getsize();j++)
      if(board->getarrayvalue(i,j)==winvalue){
        win();
        return;
      }



  if (board->nospace==true)
    gameover();

}

int Game::getscore(){
  return board->score;
}

void Game::win(){
    youwin=true;

}


void Game::gameover(){
  gameisover=true;
}
