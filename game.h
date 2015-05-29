#ifndef GAME_H
#define GAME_H

class Game{

public:
  Game();

    void win();
    void gameover();
    void restart();
    void giverandtwo();
    int getvalue(int i,int j);
    int getscore();
    static const int winvalue=2048;
    bool youwin,gameisover;
    static const int size=4;
    int bestscore;
    int boardarray[size][size];
    int regretarray[size][size];
    int score;
    bool doesitmove;
    bool checknospace();
    bool checkcantplus();
    void countscore(int getpoints);
    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    void regret();

private:

};


#endif
