#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "newbook.h"
#include "newuser.h"
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
    {
        ui->tabWidget->removeTab(1);
        ui->pushButtonBook->setDisabled(true);
    }
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

    ui->tablePepole->setRowCount(0);
    for(int i = 0; i < db->workers.count(); i++)
    {
        ui->tablePepole->insertRow(i);
        QTableWidgetItem *item_userLastName = new QTableWidgetItem(db->workers[i].getLastName());
        QTableWidgetItem *item_userFirstName = new QTableWidgetItem(db->workers[i].getFirstName());
        QTableWidgetItem *item_userPatronymic = new QTableWidgetItem(db->workers[i].getPatronymic());
        QTableWidgetItem *item_userRank = new QTableWidgetItem("Библиотекарь");
        if(db->workers[i].getAdministrator())
            item_userRank = new QTableWidgetItem("Администратор");
        QTableWidgetItem *item_userHomeAddress = new QTableWidgetItem(db->workers[i].getHomeAddress());
        QTableWidgetItem *item_userReaderNumber = new QTableWidgetItem("-");


        ui->tablePepole->setItem(i,0,item_userLastName);
        ui->tablePepole->setItem(i,1,item_userFirstName);
        ui->tablePepole->setItem(i,2,item_userPatronymic);
        ui->tablePepole->setItem(i,2,item_userRank);
        ui->tablePepole->setItem(i,3,item_userHomeAddress);
        ui->tablePepole->setItem(i,4,item_userReaderNumber);
    }

    for(int i = 0; i < db->readers.count(); i++)
    {
        ui->tablePepole->insertRow(i);
        qDebug() << db->readers[i].getLastName();
        QTableWidgetItem *item_userLastName = new QTableWidgetItem(db->readers[i].getLastName());
        QTableWidgetItem *item_userFirstName = new QTableWidgetItem(db->readers[i].getFirstName());
        QTableWidgetItem *item_userPatronymic = new QTableWidgetItem(db->readers[i].getPatronymic());
        QTableWidgetItem *item_userHomeAddress = new QTableWidgetItem(db->readers[i].getHomeAddress());
        QTableWidgetItem *item_userReaderNumber = new QTableWidgetItem(db->readers[i].getReaderNumber());


        ui->tablePepole->setItem(i,0,item_userLastName);
        ui->tablePepole->setItem(i,1,item_userFirstName);
        ui->tablePepole->setItem(i,2,item_userPatronymic);
        ui->tablePepole->setItem(i,3,item_userHomeAddress);
        ui->tablePepole->setItem(i,4,item_userReaderNumber);
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

void MainWindow::createNewUser()
{
    newuser window;
    window.deliverUserRank(db->userRank);
    window.setModal(true);
    if(window.exec() == QDialog::Accepted)
        {

        if(window.isWorker()==0)
        {
            readersinfo user = window.createReaders();
            db->readers.append(user);
            updateTableBooks();
            db->saveReaders();
        }
        else
        {
            workersinfo user = window.createWorkers();
            db->workers.append(user);
            updateTableBooks();
            db->saveWorkers();
        }
        }
}
