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
  void moveup();
  void movedown();
  void moveleft();
  void moveright();

  int boardarray[size][size];
  int *randarray[size*size];




};

#endif
