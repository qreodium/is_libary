#ifndef LOADBOOKS_H
#define LOADBOOKS_H

#include <QMainWindow>
#include <booksinfo.h>
#include <workersinfo.h>
#include <readersinfo.h>
#include <QList>

class database : public QMainWindow
{
    Q_OBJECT


private:


public:
    int userRank = 0;
    QList<booksinfo> books;
    QList<workersinfo> workers;
    QList<readersinfo> readers;

    explicit database(QWidget *parent = nullptr);
    void loadBooks();
    void saveBooks();
    void loadWorkers();
    void saveWorkers();
    void loadReaders();
    void saveReaders();

signals:

};

#endif // LOADBOOKS_H
