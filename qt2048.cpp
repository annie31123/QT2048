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