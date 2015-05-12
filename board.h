#ifndef BOARD_H
#define BOARD_H

enum Direction { UP, DOWN, LEFT, RIGHT };


class Board{

public:

  void boardmain();
  void move(Direction direction);
  void makerand2();
  int getsize();
  int getarrayvalue(int i,int j);

  static const int size=4;
  int score;
  bool nospace;

private:

  void countscore(int getpoints);
  void moveup(int i,int j);
  void movedown(int i,int j);
  void moveleft(int i,int j);
  void moveright(int i,int j);

  int boardarray[size][size];
  int *randarray[size*size];




};

#endif
