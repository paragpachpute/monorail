#include "history.h"
#include "ui_history.h"
#include"sqlconnect.cpp"
#include "user.cpp"


history::history(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    sqlconnect sql;
    if(sql.createConnection()){
        QString name = user::username;
        qDebug() << name;

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select ticket.ticketId, ticket.classType, ticket.purchaseTime, ticket.fare, ticket.ticketType,"
                        " ticket.source, ticket.destination  from ticket join person "
                        "on(ticket.userId = person.personId) where name='" + name + "'" );


       ui->tableView->setModel(model);
    }
    else{
        qDebug() << "connect error";
    }

}

history::~history()
{
    delete ui;
}
