#include "editbook.h"
#include "ui_editbook.h"

editBook::editBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editBook)
{
    ui->setupUi(this);
}

editBook::~editBook()
{
    delete ui;
}

int editBook::getResult()
{
    return numberButton;
}

void editBook::clickedFirst()
{
    numberButton = 0;
    this->accept();
}

void editBook::clickedSecond()
{
    numberButton = 1;
    this->accept();
}

void editBook::clickedThird()
{
    numberButton = 2;
    this->accept();
}
