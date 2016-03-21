#include "showfare.h"
#include "ui_showfare.h"

ShowFare::ShowFare(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowFare)
{
    ui->setupUi(this);
}

ShowFare::~ShowFare()
{
    delete ui;
}
