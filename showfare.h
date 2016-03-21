#ifndef SHOWFARE_H
#define SHOWFARE_H

#include <QMainWindow>

namespace Ui {
class ShowFare;
}

class ShowFare : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowFare(QWidget *parent = 0);
    ~ShowFare();

private:
    Ui::ShowFare *ui;
};

#endif // SHOWFARE_H
