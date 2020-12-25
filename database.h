#ifndef LOADBOOKS_H
#define LOADBOOKS_H

#include <QMainWindow>
#include <booksinfo.h>

class database : public QMainWindow
{
    Q_OBJECT


private:
    int maxBooks;
    int maxReaders;
    int maxEmployee;
    int maxBusyBooks;

public:
    explicit database(QWidget *parent = nullptr);
    int test();
    booksinfo* book = new booksinfo("QString _bookTitle", "QString _author", 56, 555, 100);
    booksinfo* book_new = new booksinfo();

signals:

};

#endif // LOADBOOKS_H
