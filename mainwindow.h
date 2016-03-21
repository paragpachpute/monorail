#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QCompleter>
#include<QSqlQueryModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool createConnection();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Next_clicked();



private:
    Ui::MainWindow *ui;
    QCompleter *Station;
    QSqlQueryModel *TrainListModel;
};

#endif // MAINWINDOW_H
