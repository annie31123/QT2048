#include "qt2048.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    playing w;
    w.show();

    return a.exec();
}
