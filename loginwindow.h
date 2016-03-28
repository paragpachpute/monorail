#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "registerwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButtonSignUp_clicked();

    void on_pushButtonLogin_clicked();

private:
    Ui::LoginWindow *ui;
    RegisterWindow *reg;
};

#endif // LOGINWINDOW_H
