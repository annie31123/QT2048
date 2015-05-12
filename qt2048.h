#ifndef QT2048_H
#define QT2048_H

#include <QWidget>

namespace Ui {
class qt2048;
}

class qt2048 : public QWidget
{
    Q_OBJECT

public:
    explicit qt2048(QWidget *parent = 0);
    ~qt2048();

private:
    Ui::qt2048 *ui;
};

#endif // QT2048_H
