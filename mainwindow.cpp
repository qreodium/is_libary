#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "newbook.h"
#include "authentication.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deliveryDatabase(database* _db)
{
    db = _db;
    db->loadBooks();
    if(db->userRank == 0)
        ui->tabWidget->removeTab(1);
    updateTableBooks();
}

void MainWindow::clickedTable(int row, int column)
{
    qDebug() << "Clecked";
    ui->tableBooks->item(row,column)->setText("Clicked");
}

void MainWindow::updateTableBooks()
{
    ui->tableBooks->setRowCount(0);
    for(int i = 0; i < db->books.count(); i++)
    {
        ui->tableBooks->insertRow(i);
        QTableWidgetItem *item_bookTitle = new QTableWidgetItem(db->books[i].getBookTitle());
        QTableWidgetItem *item_bookAuthor = new QTableWidgetItem(db->books[i].getAuthor());
        QTableWidgetItem *item_bookNumberOfPages = new QTableWidgetItem(QString::number(db->books[i].getNumberOfPages()));
        QTableWidgetItem *item_bookCost = new QTableWidgetItem(QString::number(db->books[i].getCost()));
        QTableWidgetItem *item_bookUniqueCode = new QTableWidgetItem(db->books[i].getUniqueCode());

        ui->tableBooks->setItem(i,0,item_bookTitle);
        ui->tableBooks->setItem(i,1,item_bookAuthor);
        ui->tableBooks->setItem(i,2,item_bookNumberOfPages);
        ui->tableBooks->setItem(i,3,item_bookCost);
        ui->tableBooks->setItem(i,4,item_bookUniqueCode);
    }
}

void MainWindow::createNewBook()
{
    newBook window;
    window.setModal(true);
    if(window.exec() == QDialog::Accepted)
        {
            booksinfo book = window.create();
            db->books.append(book);
            updateTableBooks();
            db->saveBooks();
        }
}
