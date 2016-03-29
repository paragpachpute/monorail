#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "loginwindow.h"
#include "user.cpp"
#include "sqlconnect.cpp"
#include "QDebug"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString username, password, cpassword, age, address, gender;
    username = ui->lineEditRUsername->text();
    password = ui->lineEditRPassword->text();
    cpassword = ui->lineEditRConfirmpassword->text();
    age = ui->lineEditRAge->text();
    address = ui->lineEditRAdd->text();
    gender = ui->lineEditRGender->text();


    int x = QString::compare(password , cpassword, Qt::CaseSensitive);
    if(x!=0) {
        QMessageBox::critical(this, tr("Error") , tr("Password's do not match"));
        ui->lineEditRPassword->setText("");
        ui->lineEditRConfirmpassword->setText("");

    }else{


        user u;

        u.setun(username);
        u.setpass(password);
        u.setadd(address);
        u.setgen(gender);
        u.setage(age);

        qDebug() << user::username;
        qDebug() << user::pass;

        sqlconnect sql;
        if(sql.createConnection())
        {
            qDebug() << "Connected!";
            QSqlQuery query;
            query.exec("insert into person values('', '" + username + "', " + age +
                       ", '" + gender + "', '" + address + "' )");

            qDebug() << "select personId from person where name='" + username + "'";

            QSqlQuery newQry;
            newQry.exec("select personId from person where name='" + username + "'");
            newQry.next();
            QString id = newQry.value(0).toString();
            qDebug() << id;

            u.setid(id);

            QString insQry = "insert into user values(" + id + ", '" + username + "', '" + password + "', '')";
            qDebug() << insQry;
            QSqlQuery newQuery;
            newQuery.exec(insQry);

            LoginWindow *l = new LoginWindow;
            l->show();
            this->hide();

        }


    }

}
