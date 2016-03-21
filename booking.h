#ifndef BOOKING_H
#define BOOKING_H

#include <QMainWindow>

namespace Ui {
class booking;
}

class booking : public QMainWindow
{
    Q_OBJECT

public:
    explicit booking(QWidget *parent = 0);
    ~booking();

private slots:
    void on_Submit_Button_clicked();

    void on_Pass_RB_clicked();

    void on_Ticket_RB_clicked();

private:
    Ui::booking *ui;
};

#endif // BOOKING_H
