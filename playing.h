#ifndef PLAYING_H
#define PLAYING_H

#include <QWidget>
#include <QPushButton>
#include "game.h"
#include "board.h"

namespace Ui {
class playing;
}

class playing : public QWidget
{
    Q_OBJECT

public:
    explicit playing(QWidget *parent = 0);
    ~playing();
    void pressthekey(QKeyEvent *pressed);
    void movethepicture();
private:
    Ui::playing *ui;
    Game *game;
};

#endif // PLAYING_H
