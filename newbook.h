#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <QDialog>
#include "booksinfo.h"
#include "mainwindow.h"



namespace Ui {
class newBook;
}

class newBook : public QDialog
{
    Q_OBJECT

public:
    explicit newBook(QWidget *parent = nullptr);
    ~newBook();
    booksinfo create();

private:
    Ui::newBook *ui;
};

#endif // NEWBOOK_H
