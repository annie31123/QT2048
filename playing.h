#ifndef PLAYING_H
#define PLAYING_H

#include <QWidget>
#include <QPushButton>
#include "game.h"
//#include "board.h"
#include <QLabel>
#include <win.h>

namespace Ui {
class playing;
}

class playing : public QWidget
{
    Q_OBJECT

public:
    explicit playing(QWidget *parent = 0);
    ~playing();
    void keyPressEvent(QKeyEvent *pressed);
    void movethepicture();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::playing *ui;
    Game game;
    QLabel* labels[16];
};

#endif // PLAYING_H
