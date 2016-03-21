#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlconnect.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    qDebug() << QSqlDatabase::drivers();
    ui->setupUi(this);
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
        Station = new QCompleter(CompletionList,this);
        Station->setCaseSensitivity((Qt::CaseInsensitive));
        ui->SourceStation->setCompleter(Station);
        ui->DestinationStation->setCompleter(Station);

    }
    else
    {
        qDebug()<<"Not Connected";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString ss = ui->SourceStation->text();
    QString ds = ui->DestinationStation->text();
    //QSqlQuery query;

   // query.exec("select * from train where source= '"+ss+"' and destination= '"+ds+"'" );
    TrainListModel=new QSqlQueryModel();
    QString sql = "select trainNo, station.name, time from haltsat join station on(haltsat.stationId = station.stationId)"
                  " where name='" + ss + "'" ;
    TrainListModel->setQuery(sql);


      ui->tableView->setModel(TrainListModel);
}

void MainWindow::on_Next_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedIndexes();
    QStringList items;
    qDebug()<<"hello"<<selected;
       foreach(QModelIndex index, selected)
       {
           QStandardItemModel* itemModel = dynamic_cast<QStandardItemModel*>(ui->tableView->model());
           if(itemModel)
           {
               QStandardItem* item = itemModel->itemFromIndex(index);
               qDebug()<< item->data().toString();
           }
       }
//    qDebug()<<TrainListModel->record(selected.first().).value("trainNo").toInt();


}

