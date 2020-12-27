#ifndef LOADBOOKS_H
#define LOADBOOKS_H

#include <QMainWindow>
#include <booksinfo.h>
#include <QList>

class database : public QMainWindow
{
    Q_OBJECT


private:


public:
    QList<booksinfo> books;
    explicit database(QWidget *parent = nullptr);
    void loadBooks();
    void saveBooks();

signals:

};

#endif // LOADBOOKS_H
