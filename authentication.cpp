#include "authentication.h"
#include "ui_authentication.h"
#include "mainwindow.h"


authentication::authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
}

authentication::~authentication()
{
    delete ui;
}


void authentication::checkPassword()
{
    database* db = new database();
    db->loadWorkers();
    db->loadReaders();
    for(int i = 0; i<db->workers.count(); i++)
    {
        if((ui->line_login->text() == db->workers[i].getLogin())&&(ui->line_password->text() == db->workers[i].getPassword()))
        {
            if(db->workers[i].getAdministrator())
                db->userRank = 2;
            else
                db->userRank = 1;
            hide();
            mui = new MainWindow();
            mui->deliveryDatabase(db);
            mui->show();
        }
    }
    for(int i = 0; i<db->readers.count(); i++)
    {
        if((ui->line_login->text() == db->readers[i].getLogin())&&(ui->line_password->text() == db->readers[i].getPassword()))
        {
            db->userRank = 0;
            hide();
            mui = new MainWindow();
            mui->deliveryDatabase(db);
            mui->show();
        }
    }
}

