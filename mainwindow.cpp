#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableBooks->setRowCount(11);
    QTableWidgetItem* item = new QTableWidgetItem;
    database* t = new database(this);
    item->setText(t->book_new->getBookTitle());
    ui->tableBooks->setItem(1,1,item);
}


MainWindow::~MainWindow()
{
    delete ui;
}

