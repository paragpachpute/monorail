#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "user.cpp"
#include <QMessageBox>
#include "homepage.h"
#include "QDebug"


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->lineEditUsername->setText(user::username);
    ui->lineEditPassword->setText(user::pass);

    qDebug() << user::username;
    qDebug() << user::pass;

}

LoginWindow::~LoginWindow()
{
    delete ui;


}

void LoginWindow::on_pushButtonSignUp_clicked()
{
    reg = new RegisterWindow(this);
    reg->show();
    this->hide();


}

void LoginWindow::on_pushButtonLogin_clicked()
{
    QString username, password;
    username = ui->lineEditUsername->text();
    password = ui->lineEditPassword->text();

    homepage *h = new homepage;
    h->show();
    this->hide();
}
