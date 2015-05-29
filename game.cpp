#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QTime>
using namespace std;

Game::Game(){
  restart();
}

void Game::restart(){
  score=0;
  for(int i=0;i<4;i++)
      for(int j=0;j<4;j++){
        boardarray[i][j]=0;
        regretarray[i][j]=0;}


  qsrand(time(NULL));
  int rand1,rand2;
  rand1=qrand()%4;
  rand2=qrand()%4;
  regretarray[rand1][rand2]=2;

  youwin=false;
  gameisover=false;
}
void Game::countscore(int getpoints){
  score=score+getpoints;

}
void Game::giverandtwo(){


    qsrand(time(NULL));
    int rand1,rand2;
    for(;;){
         rand1=qrand()%4;
         rand2=qrand()%4;
     if(boardarray[rand1][rand2]==0){
       boardarray[rand1][rand2]=2;
     break;}
    }

}

int Game::getvalue(int i,int j){
    return boardarray[i][j];
}



int Game::getscore(){
  return score;
}

void Game::win(){

    youwin=true;

}


void Game::gameover(){

  gameisover=true;
}

void Game::moveup(){
    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
          if(boardarray[i][j]!=0)
          for(int k=1;k<=i;k++){

            if(boardarray[i-k][j]==0){
                boardarray[i-k][j]=boardarray[i-k+1][j];
                boardarray[i-k+1][j]=0;
                doesitmove=true;
            }
          }
      }}

    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
          if(boardarray[i][j]!=0)
        if(boardarray[i][j]==boardarray[i-1][j]){
            boardarray[i-1][j]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i-1][j]);
            doesitmove=true;
        }
      }}

    for(int j=0;j<size;j++ ){
      for(int i=1;i<size;i++){
          if(boardarray[i][j]!=0)
          for(int k=1;k<=i;k++)
        if(boardarray[i-k][j]==0){
            boardarray[i-k][j]=boardarray[i-k+1][j];
            boardarray[i-k+1][j]=0;
            doesitmove=true;

         }

      }}

    if(doesitmove==true)
        giverandtwo();

    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(boardarray[i][j]==2048){
          win();
          return;
        }


if (checknospace()==true)
    if(checkcantplus()==true)
      gameover();

return;


}


void Game::movedown(){
      for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i--){
        if(boardarray[i][j]!=0)
          for(int k=1;k<=3-i;k++)
        if(boardarray[i+k][j]==0){
            boardarray[i+k][j]=boardarray[i+k-1][j];
            boardarray[i+k-1][j]=0;
            doesitmove=true;
        }
     }}

    for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i--){
          if(boardarray[i][j]!=0)
        if(boardarray[i][j]==boardarray[i+1][j]){
            boardarray[i+1][j]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i+1][j]);
            doesitmove=true;
        }
     }}

    for(int j=0;j<size;j++ ){
      for(int i=size-2;i>-1;i--){
         if(boardarray[i][j]!=0)
          for(int k=1;k<=3-i;k++)
        if(boardarray[i+k][j]==0){
            boardarray[i+k][j]=boardarray[i+k-1][j];
            boardarray[i+k-1][j]=0;
            doesitmove=true;
        }
     }}

    if(doesitmove==true)
    giverandtwo();

    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(boardarray[i][j]==2048){
          win();
          return;
        }



    if (checknospace()==true)
        if(checkcantplus()==true)
      gameover();

    return;
}

void Game::moveleft(){
     for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
        if(boardarray[i][j]!=0)
          for(int k=1;k<=j;k++)
        if(boardarray[i][j-k]==0){
            boardarray[i][j-k]=boardarray[i][j-k+1];
            boardarray[i][j-k+1]=0;
            doesitmove=true;
        }
    }}


    for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
          if(boardarray[i][j]!=0)
        if(boardarray[i][j-1]==boardarray[i][j]){
            boardarray[i][j-1]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i][j-1]);
            doesitmove=true;
        }
    }}

    for(int i=0;i<size;i++){
      for(int j=1;j<size;j++){
        if(boardarray[i][j]!=0)
          for(int k=1;k<=j;k++)
        if(boardarray[i][j-k]==0){
            boardarray[i][j-k]=boardarray[i][j-k+1];
            boardarray[i][j-k+1]=0;
            doesitmove=true;
        }
    }}

    if(doesitmove==true)
    giverandtwo();

    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(boardarray[i][j]==2048){
          win();
          return;
        }



    if (checknospace()==true)
        if(checkcantplus()==true)
      gameover();

    return;
}

void Game::moveright(){
    for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j--){
        if(boardarray[i][j]!=0)
          for(int k=1;k<=3-j;k++)
        if(boardarray[i][j+k]==0){
            boardarray[i][j+k]=boardarray[i][j+k-1];
            boardarray[i][j+k-1]=0;
            doesitmove=true;
        }
    }}

    for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j--){
          if(boardarray[i][j]!=0)
        if(boardarray[i][j+1]==boardarray[i][j]){
            boardarray[i][j+1]=boardarray[i][j]*2;
            boardarray[i][j]=0;
            countscore(boardarray[i][j+1]);
            doesitmove=true;
         }
    }}

   for(int i=0;i<size;i++){
      for(int j=size-2;j>-1;j--){
        if(boardarray[i][j]!=0)
          for(int k=1;k<=3-j;k++)
        if(boardarray[i][j+k]==0){
            boardarray[i][j+k]=boardarray[i][j+k-1];
            boardarray[i][j+k-1]=0;
            doesitmove=true;
        }
    }}
   if(doesitmove==true)
    giverandtwo();

    for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
        if(boardarray[i][j]==2048){
          win();
          return;
        }



    if (checknospace()==true)
        if(checkcantplus()==true)
      gameover();

    return;
}

bool Game::checkcantplus(){
    for(int i=0;i<4;i++)
        for(int j=0;j<3;j++)
            if(boardarray[i][j]==boardarray[i][j+1])
                return false;

    for(int j=0;j<4;j++)
        for(int i=0;i<3;i++)
            if(boardarray[i][j]==boardarray[i+1][j])
                return false;



    return true;

}

bool Game::checknospace(){

    int count=0;

     for(int i=0;i<size;i++){
      for(int j=0;j<size;j++){
        if (boardarray[i][j]==0){
          count++;
        } } }

    if (count==0){

      return true;
    }

return false;

}

void Game::regret(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            boardarray[i][j]=regretarray[i][j];
}
