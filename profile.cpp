#include "profile.h"
#include "ui_profile.h"
#include"sqlconnect.cpp"

QString id, name, age, gender, add;

profile::profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);

    sqlconnect sql;
    if(sql.createConnection()){
        QSqlQuery query;
        QString uname = "parag";
        QString sqlQuery = "select * from person where name='" + uname + "'";
        query.exec(sqlQuery);
        while (query.next()) {
               id = query.value(0).toString();
               name = query.value(1).toString();
               age = query.value(2).toString();
               gender = query.value(3).toString();
               add = query.value(4).toString();

               ui->idL->setText(id);
               ui->nameL->setText(name);
               ui->ageL->setText(age);
               ui->genL->setText(gender);
               ui->addL->setText(add);

               qDebug() << id ;
               qDebug() << name ;
               qDebug() << age ;
               qDebug() << gender ;
               qDebug() << add ;
        }

    }
    else{
        qDebug() << "connect error";
    }
}

profile::~profile()
{
    delete ui;
}
