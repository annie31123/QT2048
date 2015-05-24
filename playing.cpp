#include "playing.h"
#include "ui_playing.h"


#include <QKeyEvent>

playing::playing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playing)
{
    ui->setupUi(this);
    labels = new QLabel*[16]{ui->label00,ui->label01,ui->label02,ui->label03,
                             ui->label10,ui->label11,ui->label12,ui->label13,
                             ui->label20,ui->label21,ui->label22,ui->label23,
                             ui->label30,ui->label31,ui->label32,ui->label33};
    game->giverandtwo();


}

playing::~playing()
{
    delete labels;
    delete ui;

}

void playing::pressthekey(QKeyEvent *pressed){

    switch (pressed->key()) {
    case Qt::Key_Left:
        game->move(LEFT);
        break;
    case Qt::Key_Up:
        game->move(UP);
        break;
    case Qt::Key_Right:
        game->move(RIGHT);
        break;
    case Qt::Key_Down:
        game->move(DOWN);
        break;

    default:
        break;
    }


    if(game->youwin==true){
     //this->close();
    }

    if (game->gameisover==true){
    //this->close();
    }

    movethepicture();
}

void playing::movethepicture(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            switch (game->getvalue(i,j)) {
            case 0:
               labels[i*4+j]->setPixmap(QPixmap(":/0.PNG"));
                break;
            case 2:
               labels[i*4+j]->setPixmap(QPixmap(":/2.PNG"));
                break;
            case 4:
               labels[i*4+j]->setPixmap(QPixmap(":/4.PNG"));
                break;
            case 8:
               labels[i*4+j]->setPixmap(QPixmap(":/8.PNG"));
                break;
            case 16:
               labels[i*4+j]->setPixmap(QPixmap(":/16.PNG"));
                break;
            case 32:
               labels[i*4+j]->setPixmap(QPixmap(":/32.PNG"));
                break;
            case 64:
               labels[i*4+j]->setPixmap(QPixmap(":/64.PNG"));
                break;
            case 128:
               labels[i*4+j]->setPixmap(QPixmap(":/128.PNG"));
                break;
            case 256:
               labels[i*4+j]->setPixmap(QPixmap(":/256.PNG"));
                break;
            case 512:
               labels[i*4+j]->setPixmap(QPixmap(":/512.PNG"));
                break;
            case 1024:
               labels[i*4+j]->setPixmap(QPixmap(":/1024.PNG"));
                break;
            case 2048:
               labels[i*4+j]->setPixmap(QPixmap(":/2048"));
                break;
            default:
                break;
            }


        }


    }






}
