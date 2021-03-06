#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "user.cpp"
#include "sqlconnect.cpp"
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

    sqlconnect sql;
    if(sql.createConnection())
    {
        qDebug() << "Connected!";
        QSqlQuery query;

        query.exec("select userId, password from user where username='" + username + "'");
        query.next();
        QString pass = query.value(1).toString();
        QString id = query.value(0).toString();
        qDebug() << id;

        if(pass == password){

            user u;
            query.exec("select * from person where personId=" + id );
            query.next();

            qDebug() << "select * from person where personId=" + id;

            u.setun(query.value(1).toString());
            u.setage(query.value(2).toString());
            u.setgen(query.value(3).toString());
            u.setadd(query.value(4).toString());
            u.setpass(password);
            u.setid(id);

            homepage *h = new homepage;
            h->show();
            this->hide();
        }else{
            QMessageBox::critical(this, tr("Error") , tr("Wrong credentials!!"));
        }

    }


}
