#ifndef QT2048_H
#define QT2048_H

#include <QWidget>
#include <QPushButton>
#include <game.h>
#include <board.h>
#include "playing.h"

namespace Ui {
class qt2048;
}

class qt2048 : public QWidget
{
    Q_OBJECT

public:
    explicit qt2048(QWidget *parent = 0);
    ~qt2048();

private slots:

    void on_start_clicked();

private:
    Ui::qt2048 *ui;
    playing *play=new (playing);

};

#endif // QT2048_H
