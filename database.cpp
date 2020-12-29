#include "database.h"
#include "config.h"
#include <QFile>

database::database(QWidget *parent) : QMainWindow(parent)
{

}

void database::loadBooks()
{
    QFile file(Config::fileBooks);
    books.clear();
    booksinfo tmp;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {//перебираем весь файл и записываем инф. о каждой книге
            ist >> tmp;
            books.append(tmp);
        }
        file.close();
    }
}

void database::saveBooks()
{
    QFile file(Config::fileBooks);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream ost(&file);
        for(int i = books.count()-1; i >= 0; i--) {//перебираем весь файл и записываем инф. о каждой книге
            ost << books[i];
        }
        file.close();
    }
}

void database::loadWorkers()
{
    QFile file(Config::fileWorkers);
    workers.clear();
    workersinfo tmp;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {//перебираем весь файл и записываем информацию
            ist >> tmp;
            workers.append(tmp);
        }
        file.close();
    }
    if(workers.count()==0)// Если нет записей добавляем системную запись администратора
    {
        tmp.setData("system","system","system",true,"-","root","228");
        workers.append(tmp);
        saveWorkers();
    }
}

void database::saveWorkers()
{
    QFile file(Config::fileWorkers);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream ost(&file);
        for(int i = workers.count()-1; i >= 0; i--) {//перебираем весь файл и записываем инф. о каждой книге
            ost << workers[i];
        }
        file.close();
    }
}


void database::loadReaders()
{
    QFile file(Config::fileReaders);
    readers.clear();
    readersinfo tmp;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {//перебираем весь файл и записываем инф. о каждой книге
            ist >> tmp;
            readers.append(tmp);
        }
        file.close();
    }
}

void database::saveReaders()
{
    QFile file(Config::fileReaders);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream ost(&file);
        for(int i = readers.count()-1; i >= 0; i--) {//перебираем весь файл и записываем инф. о каждой книге
            ost << readers[i];
        }
        file.close();
    }
}

void database::loadRented()
{
    QFile file(Config::fileRented);
    rented.clear();
    rentedinfo tmp;
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {//перебираем весь файл и записываем инф. о каждой книге
            ist >> tmp;
            rented.append(tmp);
        }
        file.close();
    }
}

void database::saveRented()
{
    QFile file(Config::fileRented);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream ost(&file);
        for(int i = rented.count()-1; i >= 0; i--) {//перебираем весь файл и записываем инф. о каждой книге
            ost << rented[i];
        }
        file.close();
    }
}
