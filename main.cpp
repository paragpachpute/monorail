#include "mainwindow.h"
#include "booking.h"
#include "history.h"
#include "profile.h"
#include "homepage.h"
#include "loginwindow.h"
#include "user.cpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();

    return a.exec();
}


QString user :: username = "";
QString user :: pass = "";
QString user :: age = "";
QString user :: gender = "";
QString user :: add = "";
QString user :: id = "";


