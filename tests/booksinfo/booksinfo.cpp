#include "booksinfo.h"
#include <QDebug>

booksinfo::booksinfo()
{

}

booksinfo::booksinfo(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode)
{
    bookTitle=_bookTitle;
    author=_author;
    numberOfPages = _numberOfPages;
    cost=_cost;
    uniqueCode =_uniqueCode;
}


void booksinfo::setData(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode)
{
    bookTitle=_bookTitle;
    author=_author;
    numberOfPages = _numberOfPages;
    cost=_cost;
    uniqueCode =_uniqueCode;
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

QString booksinfo::getUniqueCode() const
{
    return uniqueCode;
}

void booksinfo::setUniqueCode(int value)
{
    uniqueCode = value;
}
