#include "playing.h"
#include "ui_playing.h"


#include <QKeyEvent>

playing::playing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playing)
{
    ui->setupUi(this);
    game->board->makerand2();


}

playing::~playing()
{
    delete ui;
}

void playing::pressthekey(QKeyEvent *pressed){

    switch (pressed->key()) {
    case Key_Left:
        game->move(LEFT);
        break;
    case Key_Up:
        game->move(UP);
        break;
    case Key_Right:
        game->move(RIGHT);
        break;
    case Key_Down:
        game->move(DOWN);
        break;

    default:
        break;
    }


    if(game->youwin==true){
     this->close();
    }

    if (game->gameisover==true){
    this->close();
    }

    movethepicture();
}

void playing::movethepicture(){


}
