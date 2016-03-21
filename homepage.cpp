#include "homepage.h"
#include "mainwindow.h"
#include "ui_homepage.h"

homepage::homepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homepage)
{
    ui->setupUi(this);
    connect(ui->bookB, SIGNAL(click()), this, SLOT(openNewWindow()));
}

homepage::~homepage()
{
    delete ui;
}

void homepage::on_searchB_clicked()
{
    mMyNewWindow = new MainWindow();
    mMyNewWindow->show();
}

void homepage::on_bookB_clicked()
{
    myBooking = new booking();
    myBooking->show();

}

void homepage::openNewWindow()
{
//    mMyNewWindow = new MainWindow(); // Be sure to destroy you window somewhere
//    mMyNewWindow->show();
}

void homepage::on_historyB_clicked()
{
    myHistory = new history();
    myHistory->show();
}

void homepage::on_profileB_clicked()
{
    myProfile = new profile();
    myProfile->show();
}

