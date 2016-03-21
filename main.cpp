#include "mainwindow.h"
#include "booking.h"
#include "history.h"
#include "profile.h"
#include "homepage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    homepage w;
    w.show();

    return a.exec();
}
