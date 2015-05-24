#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void Board::move(Direction direction){

  switch (direction){

    case UP:
          moveup();
      break;
    case DOWN:
          movedown();
      break;
    case LEFT:
          moveleft();
        break;
    case RIGHT:
          moveright();
      break;
  }


}



void Board::moveup(){
    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
        if(boardarray[i-1][j]==0){
            boardarray[i-1][j]=boardarray[i][j];
            boardarray[i][j]=0;
         }

      }}

    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
        if(boardarray[i][j]==boardarray[i-1][j]){
            boardarray[i-1][j]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i-1][j]);
        }
      }}

    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
        if(boardarray[i-1][j]==0){
            boardarray[i-1][j]=boardarray[i][j];
            boardarray[i][j]=0;
         }

      }}



    return;
}


void Board::movedown(){

    for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i++){
        if(boardarray[i+1][j]==0){
            boardarray[i+1][j]=boardarray[i][j];
            boardarray[i][j]=0;
        }
     }}

    for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i++){
        if(boardarray[i][j]==boardarray[i+1][j]){
            boardarray[i+1][j]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i+1][j]);
        }
     }}

    for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i++){
        if(boardarray[i+1][j]==0){
            boardarray[i+1][j]=boardarray[i][j];
            boardarray[i][j]=0;
        }
     }}

    return;
}

void Board::moveleft(){

    for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
        if(boardarray[i][j-1]==0){
            boardarray[i][j-1]=boardarray[i][j];
            boardarray[i][j]=0;
        }
    }}


    for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
        if(boardarray[i][j-1]==boardarray[i][j]){
            boardarray[i][j-1]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i][j-1]);
        }
    }}

    for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
        if(boardarray[i][j-1]==0){
            boardarray[i][j-1]=boardarray[i][j];
            boardarray[i][j]=0;
        }
    }}

    return;
}

void Board::moveright(){

    for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j++){
        if(boardarray[i][j+1]==0){
            boardarray[i][j+1]=boardarray[i][j];
            boardarray[i][j]=0;
        }
    }}

    for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j++){
        if(boardarray[i][j+1]==boardarray[i][j]){
            boardarray[i][j+1]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i][j+1]);
         }
    }}

    for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j++){
        if(boardarray[i][j+1]==0){
            boardarray[i][j+1]=boardarray[i][j];
            boardarray[i][j]=0;
        }
    }}

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
