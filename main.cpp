#include "qt2048.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt2048 w;
    w.show();

    return a.exec();
}
