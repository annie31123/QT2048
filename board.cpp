#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void Board::move(Direction direction){

  switch (direction){

    case UP:
      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
          moveup(i,j);

    case DOWN:
      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
          movedown(i,j);

    case LEFT:
      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
          moveleft(i,j);

    case RIGHT:
      for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
          moveright(i,j);
  }


}



void Board::moveup(int i,int j){
    if (i==0)
      return;

     if(boardarray[i-1][j]==0){
      boardarray[i-1][j]=boardarray[i][j];
      boardarray[i][j]=0;
     }

     if(boardarray[i][j]==boardarray[i-1][j]){
      boardarray[i-1][j]=boardarray[i][j]*2;
      boardarray[i][j]=0;
      countscore(boardarray[i-1][j]);
     }

    return;
}

void Board::movedown(int i,int j){
    if (i==size-1)
      return;

     if(boardarray[i+1][j]==0){
      boardarray[i+1][j]=boardarray[i][j];
      boardarray[i][j]=0;
     }

     if(boardarray[i][j]==boardarray[i+1][j]){
      boardarray[i+1][j]=boardarray[i][j]*2;
      boardarray[i][j]=0;
      countscore(boardarray[i+1][j]);
     }

    return;
}

void Board::moveleft(int i,int j){
    if (j==0)
      return;

     if(boardarray[i][j-1]==0){
      boardarray[i][j-1]=boardarray[i][j];
      boardarray[i][j]=0;
     }

     if(boardarray[i][j-1]==boardarray[i][j]){
      boardarray[i][j-1]=boardarray[i][j]*2;
      boardarray[i][j]=0;
      countscore(boardarray[i][j-1]);
     }

    return;
}

void Board::moveright(int i,int j){
    if (j==size-1)
      return;

     if(boardarray[i][j+1]==0){
      boardarray[i][j+1]=boardarray[i][j];
      boardarray[i][j]=0;
     }

     if(boardarray[i][j+1]==boardarray[i][j]){
      boardarray[i][j+1]=boardarray[i][j]*2;
      boardarray[i][j]=0;
      countscore(boardarray[i][j+1]);
     }

    return;
}


void Board::countscore(int getpoints){
  score=score+getpoints;
}

void Board::makerand2(){

  int count=0;
  for(int i=0;i<size*size;i++)
    randarray[size*size]=NULL;

  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if (boardarray[i][j]==0){
        randarray[count]=&boardarray[i][j];
        count++;
      } } }

  if (count==0){
    nospace=true;
    return;
  }

  srand(time(NULL));

  int randposition=rand()%count;

  *randarray[randposition]=2;
  nospace=false;

}

int Board::getsize(){
  return size;
}

int Board::getarrayvalue(int i,int j){
  return boardarray[i][j];
}
