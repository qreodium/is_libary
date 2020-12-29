#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "newbook.h"
#include "newuser.h"
#include "edituser.h"
#include "editbook.h"
#include "selectreader.h"
#include "rentedinfo.h"
#include "authentication.h"

#include <QDebug>
#include <QMessageBox>


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
    db->loadRented();
    if(db->userRank == 0)
    {
        ui->tabWidget->removeTab(1);
        ui->pushButtonBook->setDisabled(true);
    }
    updateTables();
}


void MainWindow::clickedTablePeople(int row)
{
    editUser window;
    window.setModal(true);
    if(window.exec() == QDialog::Accepted)
    {
        if(window.getResult()==0) // выдать книгу
        {
            if(ui->tablePepole->item(row,3)->text()!="Читатель")
                QMessageBox::warning(this, "Ошибка","Нельзя выдать книгу работнику.");
        }
        else if(window.getResult()==1) // списать книгу
            {
                if(ui->tablePepole->item(row,3)->text()!="Читатель")
                    QMessageBox::warning(this, "Ошибка","Нельзя списать книгу с работника.");
            }
        else if(window.getResult()==2) // удалить пользователя
        {
            if(ui->tablePepole->item(row,3)->text()=="Читатель")
            {
                db->readers.removeAt(ui->tablePepole->item(row, 0)->data(Qt::UserRole).toUInt());
                db->saveReaders();
            }
            else
            {
                db->workers.removeAt(ui->tablePepole->item(row, 0)->data(Qt::UserRole).toUInt());
                db->saveWorkers();
            }
            updateTables();
        }
    }
}

void MainWindow::clickedTableBook(int row)
{
    editBook window;
    window.setModal(true);
    if(window.exec() == QDialog::Accepted)
    {
        if(window.getResult()==2)// удалить книгу
        {
            db->books.removeAt(ui->tableBooks->item(row, 0)->data(Qt::UserRole).toUInt());
            updateTables();
        }
        else if(window.getResult()==1)// списать книгу
        {
            bool deleted = false;
            for(int i=0;i<db->rented.count();i++)
            {
                if(db->rented[i].getUniqueCode()==ui->tableBooks->item(row, 4)->text())
                {
                    db->rented.removeAt(i);
                    db->saveRented();
                    updateTables();
                    deleted = true;
                }
            }
            if(!deleted)
                QMessageBox::warning(this, "Ошибка","Книга уже находится в библиотеке.");
        }
        else if(window.getResult()==0)// выдать книгу
        {
            bool isRented = false;
            for(int i=0;i<db->rented.count();i++)
            {
                if(db->rented[i].getUniqueCode()==ui->tableBooks->item(row, 4)->text())
                    isRented = true;
            }
            if(isRented)
                QMessageBox::warning(this, "Ошибка","Книга уже забрал другой человек.");
                else
            {
            selectReader windowReaders;
            windowReaders.deliverDatabase(db);
            windowReaders.setModal(true);
            if(windowReaders.exec() == QDialog::Accepted)
            {
                int readerNumber = windowReaders.getReaderNumber();
                QDate start = QDate::currentDate();
                QDate stop = start.addDays(30);
                rentedinfo tmp(ui->tableBooks->item(row, 4)->text(),readerNumber,start,stop);
                db->rented.append(tmp);
                db->saveRented();
                updateTables();
            }
            }
        }
    }
}

void MainWindow::updateTables()
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
        QTableWidgetItem *item_bookReaderNumber = new QTableWidgetItem("");
        QTableWidgetItem *item_bookStartDate = new QTableWidgetItem("");
        QTableWidgetItem *item_bookEndDate = new QTableWidgetItem("");
        for(int j = 0; j < db->rented.count(); j++)
        {
            if(db->books[i].getUniqueCode()==db->rented[j].getUniqueCode())
            {
                item_bookReaderNumber->setText(QString::number(db->rented[j].getReaderNumber()));
                item_bookStartDate->setText(db->rented[j].getStart().toString(Qt::ISODate));
                item_bookEndDate->setText(db->rented[j].getEnd().toString(Qt::ISODate));
            }
        }

        item_bookTitle->setData(Qt::UserRole,i);
        ui->tableBooks->setItem(i,0,item_bookTitle);
        ui->tableBooks->setItem(i,1,item_bookAuthor);
        qDebug() << item_bookNumberOfPages->text();
        ui->tableBooks->setItem(i,2,item_bookNumberOfPages);
        ui->tableBooks->setItem(i,3,item_bookCost);
        ui->tableBooks->setItem(i,4,item_bookUniqueCode);
        ui->tableBooks->setItem(i,5,item_bookReaderNumber);
        ui->tableBooks->setItem(i,6,item_bookStartDate);
        ui->tableBooks->setItem(i,7,item_bookEndDate);



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

        item_userLastName->setData(Qt::UserRole,i);
        ui->tablePepole->setItem(i,0,item_userLastName);
        ui->tablePepole->setItem(i,1,item_userFirstName);
        ui->tablePepole->setItem(i,2,item_userPatronymic);
        ui->tablePepole->setItem(i,3,item_userRank);
        ui->tablePepole->setItem(i,4,item_userHomeAddress);
        ui->tablePepole->setItem(i,5,item_userReaderNumber);
    }

    for(int i = 0; i < db->readers.count(); i++)
    {
        ui->tablePepole->insertRow(i);
        QTableWidgetItem *item_userLastName = new QTableWidgetItem(db->readers[i].getLastName());
        QTableWidgetItem *item_userFirstName = new QTableWidgetItem(db->readers[i].getFirstName());
        QTableWidgetItem *item_userPatronymic = new QTableWidgetItem(db->readers[i].getPatronymic());
        QTableWidgetItem *item_userRank = new QTableWidgetItem("Читатель");
        QTableWidgetItem *item_userHomeAddress = new QTableWidgetItem(db->readers[i].getHomeAddress());
        QTableWidgetItem *item_userReaderNumber = new QTableWidgetItem(QString::number(db->readers[i].getReaderNumber()));

        item_userLastName->setData(Qt::UserRole,i);
        ui->tablePepole->setItem(i,0,item_userLastName);
        ui->tablePepole->setItem(i,1,item_userFirstName);
        ui->tablePepole->setItem(i,2,item_userPatronymic);
        ui->tablePepole->setItem(i,3,item_userRank);
        ui->tablePepole->setItem(i,4,item_userHomeAddress);
        ui->tablePepole->setItem(i,5,item_userReaderNumber);
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
            updateTables();
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
            updateTables();
            db->saveReaders();
        }
        else
        {
            workersinfo user = window.createWorkers();
            db->workers.append(user);
            updateTables();
            db->saveWorkers();
        }
        }
}
