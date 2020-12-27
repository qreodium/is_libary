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
    qDebug() << db->workers.count();
    for(int i = 0; i<db->workers.count(); i++)
    {
        if((ui->line_login->text() == db->workers[i].getLogin())&&(ui->line_password->text() == db->workers[i].getPassword()))
        {
            if(db->workers[i].getAdministrator())
                db->userRank = 1;
            else
                db->userRank = 2;
            hide();
            mui = new MainWindow();
            mui->deliveryDatabase(db);
            mui->show();
        }
    }
}

