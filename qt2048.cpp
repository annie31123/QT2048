#include "qt2048.h"
#include "ui_qt2048.h"

qt2048::qt2048(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qt2048)
{
    ui->setupUi(this);


}

qt2048::~qt2048()
{
    delete ui;
}



void qt2048::on_start_clicked()
{
     play->show();
    this->close();
}

