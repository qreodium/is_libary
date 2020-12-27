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
        tmp.setData("system","system","system",true,"no","root","228");
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



