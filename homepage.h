#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include"mainwindow.h"
#include"profile.h"
#include"history.h"
#include"booking.h"

namespace Ui {
class homepage;
}

class homepage : public QMainWindow
{
    Q_OBJECT

public slots:
   void openNewWindow();

public:
    explicit homepage(QWidget *parent = 0);
    ~homepage();

private slots:
    void on_searchB_clicked();

    void on_bookB_clicked();

    void on_historyB_clicked();

    void on_profileB_clicked();

private:
    Ui::homepage *ui;
    MainWindow *mMyNewWindow;
    profile *myProfile;
    history *myHistory;
    booking *myBooking;
};

#endif // HOMEPAGE_H
