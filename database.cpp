#include "database.h"
#include "config.h"

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
        for(int i = books.count(); i > 0; i--) {//перебираем весь файл и записываем инф. о каждой книге
            ost << books[i];
        }
        file.close();
    }
}



