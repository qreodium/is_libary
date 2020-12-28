#include "edituser.h"
#include "ui_edituser.h"

#include <QDebug>

editUser::editUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editUser)
{
    ui->setupUi(this);
}

editUser::~editUser()
{
    delete ui;
}

int editUser::getResult()
{
    return numberButton;
}

void editUser::clickedFirst()
{
    numberButton = 0;
    this->accept();
}

void editUser::clickedSecond()
{
    numberButton = 1;
    this->accept();
}

void editUser::clickedThird()
{
    numberButton = 2;
    this->accept();
}
