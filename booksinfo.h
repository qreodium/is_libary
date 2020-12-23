#ifndef BOOKSINFO_H
#define BOOKSINFO_H

#include <QString>
#include <QFile>
#include <QDataStream>
#include <QDebug>


class booksinfo
{
private:
    QString bookTitle;
    QString author;
    int numberOfPages;
    int cost;
    int uniqueCode;
public:
    booksinfo();
    booksinfo(QString _bookTitle, QString _author, int _numberOfPages, int _cost, int _uniqueCode);
    booksinfo getInfo(int number);
    void setInfo(int number);
    QString getBookTitle() const;
    void setBookTitle(const QString &value);
    QString getAuthor() const;
    void setAuthor(const QString &value);
    int getNumberOfPages() const;
    void setNumberOfPages(int value);
    int getCost() const;
    void setCost(int value);
    int getUniqueCode() const;
    void setUniqueCode(int value);
};

#endif // BOOKSINFO_H
