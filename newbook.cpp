#include "newbook.h"
#include "ui_newbook.h"

newBook::newBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newBook)
{
    ui->setupUi(this);
}

newBook::~newBook()
{
    delete ui;
}

booksinfo newBook::create()
{
    booksinfo book(ui->lineEdit_bookTitle->text(),ui->lineEdit_bookAuthor->text(),ui->spinBox_bookPages->text().toUInt(),
                   ui->spinBox_bookCost->text().toUInt(),ui->lineEdit_bookUniqueCode->text());
    return book;
}
