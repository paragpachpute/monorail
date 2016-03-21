#include "history.h"
#include "ui_history.h"
#include"sqlconnect.cpp"


history::history(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    sqlconnect sql;
    if(sql.createConnection()){
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("select ticket.* from ticket join person "
                                 "on(ticket.userId = person.personId) where name=\"rushab\" " );


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
