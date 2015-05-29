#include "playing.h"
#include "ui_playing.h"
#include <QString>
#include <QKeyEvent>

playing::playing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playing)
{
    ui->setupUi(this);
    game.bestscore=0;
    ui->label_bestscore->setText("0");
    labels[0]=ui->label00;
    labels[1]=ui->label01;
    labels[2]=ui->label02;
    labels[3]=ui->label03;
    labels[4]=ui->label10;
    labels[5]=ui->label11;
    labels[6]=ui->label12;
    labels[7]=ui->label13;
    labels[8]=ui->label20;
    labels[9]=ui->label21;
    labels[10]=ui->label22;
    labels[11]=ui->label23;
    labels[12]=ui->label30;
    labels[13]=ui->label31;
    labels[14]=ui->label32;
    labels[15]=ui->label33;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
          game.boardarray[i][j]=0;

    ui->label_winlose->setText(" ");
    game.giverandtwo();
    movethepicture();
}

playing::~playing()
{
   delete ui;

}

void playing::keyPressEvent(QKeyEvent *pressed){

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            game.regretarray[i][j]=game.boardarray[i][j];

    game.doesitmove=false;
    switch (pressed->key()) {
    case Qt::Key_Left:
        game.moveleft();
        break;
    case Qt::Key_Up:
        game.moveup();
        break;
    case Qt::Key_Right:
        game.moveright();
        break;
    case Qt::Key_Down:
        game.movedown();
        break;

    default:
        break;
    }


    if(game.youwin==true){  
     ui->label_winlose->setText("YOU WIN");

     if(game.score>game.bestscore)
         game.bestscore=game.score;
     QString S;
     S = QString :: number(game.bestscore,10);
     ui->label_bestscore->setText(S);
    }

    if (game.gameisover==true){
     ui->label_winlose->setText("YOU LOSE");

     if(game.score>game.bestscore)
         game.bestscore=game.score;
     QString S;
     S = QString :: number(game.bestscore,10);
     ui->label_bestscore->setText(S);
    }

    movethepicture();
}

void playing::movethepicture(){

 for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            switch (game.boardarray[i][j]) {
            case 0:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/0.PNG"));
                break;
            case 2:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/2.PNG"));
                break;
            case 4:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/4.PNG"));
                break;
            case 8:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/8.PNG"));
                break;
            case 16:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/16.PNG"));
                break;
            case 32:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/32.PNG"));
                break;
            case 64:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/64.PNG"));
                break;
            case 128:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/128.PNG"));
                break;
            case 256:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/256.PNG"));
                break;
            case 512:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/512.PNG"));
                break;
            case 1024:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/1024.PNG"));
                break;
            case 2048:
               labels[i*4+j]->setPixmap(QPixmap(":/new/prefix1/2048.PNG"));
                break;
            default:
                break;
            }


        }


    }

    QString Star;
    Star = QString :: number(game.getscore(),10);
    ui->label_score->setText(Star);


}

void playing::on_pushButton_2_clicked()
{
    game.restart();
    game.giverandtwo();
    movethepicture();
    ui->label_winlose->setText(" ");
}

void playing::on_pushButton_4_clicked()
{
    game.regret();
    movethepicture();
    ui->label_winlose->setText(" ");

}
