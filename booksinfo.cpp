#include "booksinfo.h"

booksinfo::booksinfo()
{

}

booksinfo::booksinfo(QString _bookTitle, QString _author, int _numberOfPages, int _cost, int _uniqueCode)
{
    bookTitle=_bookTitle;
    author=_author;
    numberOfPages = _numberOfPages;
    cost=_cost;
    uniqueCode =_uniqueCode;
}

booksinfo booksinfo::getInfo(int number)
{
    QFile file("booksinfo.bin");
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&file);
        stream.setVersion (QDataStream::Qt_4_2) ;
        stream >> bookTitle >> author >> numberOfPages >> cost >> uniqueCode;
        if(stream.status() != QDataStream::Ok)
        {
            qDebug() << "Ошибка чтения файла";
        }
    file.close();
    }
}

void booksinfo::setInfo(int number)
{
    QFile file("booksinfo.bin");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        stream.setVersion(QDataStream::Qt_4_2);
        stream << bookTitle << author << numberOfPages << cost << uniqueCode;
        if(stream.status() != QDataStream::Ok)
        {
            qDebug() << "Ошибка записи";
        }
    }
    file.close();
}

QString booksinfo::getBookTitle() const
{
    return bookTitle;
}

void booksinfo::setBookTitle(const QString &value)
{
    bookTitle = value;
}

QString booksinfo::getAuthor() const
{
    return author;
}

void booksinfo::setAuthor(const QString &value)
{
    author = value;
}

int booksinfo::getNumberOfPages() const
{
    return numberOfPages;
}

void booksinfo::setNumberOfPages(int value)
{
    numberOfPages = value;
}

int booksinfo::getCost() const
{
    return cost;
}

void booksinfo::setCost(int value)
{
    cost = value;
}

int booksinfo::getUniqueCode() const
{
    return uniqueCode;
}

void booksinfo::setUniqueCode(int value)
{
    uniqueCode = value;
}
