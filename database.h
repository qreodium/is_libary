#ifndef LOADBOOKS_H
#define LOADBOOKS_H

#include <QMainWindow>
#include <booksinfo.h>

class database : public QMainWindow
{
    Q_OBJECT
public:
    explicit database(QWidget *parent = nullptr);
    int test();
    booksinfo* book = new booksinfo("QString _bookTitle", "QString _author", 56, 555, 100);

private:


signals:

};

#endif // LOADBOOKS_H
