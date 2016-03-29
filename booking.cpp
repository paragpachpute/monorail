#include "booking.h"
#include "ui_booking.h"
#include"mainwindow.h"
#include"sqlconnect.cpp"
#include "user.cpp"
#include<string>
#include<qDebug>
#include<QVBoxLayout>
#include<QtCore>
#include<QtGui>
#include<QMessageBox>
#include<QCompleter>

using namespace std;

string source;
string dest;
bool ticketClass;
bool type;
string startDate;
bool duration;
int fare;


booking::booking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::booking)
{
    ui->StartDate_LE->
    ui->setupUi(this);
    ui->FClass_RB->setChecked(true);
    ui->Ticket_RB->setChecked(true);
    ui->OneMonth_RB->setChecked(true);
    ui->OneMonth_RB->setCheckable(false);
    ui->ThreeMonths_RB->setCheckable(false);
    ui->StartDate_LE->setEnabled(false);

    sqlconnect sql;
    if(sql.createConnection())
    {
        qDebug() << "Connected!";
        QSqlQuery query;
        QStringList CompletionList;
        query.exec("select name from station");
        while (query.next()) {
               QString name = query.value(0).toString();
               CompletionList << name;
               qDebug() << name ;
        }
        QCompleter *Station = new QCompleter(CompletionList,this);
        Station->setCaseSensitivity((Qt::CaseInsensitive));
        ui->Source_LE->setCompleter(Station);
        ui->Destination_LE->setCompleter(Station);

    }
    else
    {
        qDebug()<<"Not Connected";
    }
}

booking::~booking()
{
    delete ui;
}

void booking::on_Submit_Button_clicked()
{
    QString source = ui->Source_LE->text();
    QString dest = ui->Destination_LE->text();
    ticketClass = ui->FClass_RB->isChecked();
    type = ui->Ticket_RB->isChecked();
    startDate = ui->StartDate_LE->text().toStdString();
    duration = ui->ThreeMonths_RB->isChecked();

    QSqlQuery query;
    QString sqlQuery = "select stationId from station where name='" + source + "'";
    query.exec(sqlQuery);
    query.next();
    QString idS = query.value(0).toString();
    int idSInt = idS.toInt();
    qDebug() << idSInt;

    sqlQuery = "select stationId from station where name='" + dest + "'";
    query.exec(sqlQuery);
    query.next();
    QString idD = query.value(0).toString();
    int idDInt = idD.toInt();
    qDebug() << idDInt;

    int cost;
    if(ticketClass)
       cost  = (idDInt-idSInt) * 50;
    else cost = (idDInt-idSInt) * 10;

    if(type)
        cost *= 1;
    else cost *= 10;

    if(duration)
        cost *= 3;

    if(cost<0) cost*=-1;
    QString msg("cost is : ");
    msg = msg + QString::number(cost);
    QMessageBox::question(this,"Title", msg);

    qDebug() << user::id;

    query.prepare("INSERT INTO ticket VALUES (?, ?, ?, now(), ?, ?, ?, ?)");
    query.addBindValue("");
    query.addBindValue((user::id).toInt());

    if(ticketClass)
        query.addBindValue("f");
    else query.addBindValue("s");

    query.addBindValue(cost);

    if(type)
        query.addBindValue("normal");
    else query.addBindValue("pass");

    query.addBindValue(source);
    query.addBindValue(dest);
    query.exec();

}

void booking::on_Pass_RB_clicked()
{
    ui->StartDate_LE->setEnabled(true);
    ui->OneMonth_RB->setCheckable(true);
    ui->ThreeMonths_RB->setCheckable(true);

}

void booking::on_Ticket_RB_clicked()
{
    ui->StartDate_LE->setEnabled(false);
    ui->OneMonth_RB->setCheckable(false);
    ui->ThreeMonths_RB->setCheckable(false);
}

