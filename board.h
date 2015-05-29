#ifndef BOARD_H
#define BOARD_H

//enum Direction { UP, DOWN, LEFT, RIGHT };


class Board{

public:
  Board();
  void boardmain();
  //void move(Direction direction);
  void makerand2();
  int getsize();
  int getarrayvalue(int i,int j);

  static const int size=4;
  int score;
  bool nospace;
int boardarray[size][size];


  void countscore(int getpoints);
  void moveup();
  void movedown();
  void moveleft();
  void moveright();
private:

  //int *randarray[size*size];




};

#endif
