#ifndef BOOKSINFO_H
#define BOOKSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>


class booksinfo
{
private:
    QString bookTitle;
    QString author;
    int numberOfPages;
    int cost;
    QString uniqueCode;
public:
    booksinfo();
    booksinfo(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode);
    void setData(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode);
    QString getBookTitle() const;
    void setBookTitle(const QString &value);
    QString getAuthor() const;
    void setAuthor(const QString &value);
    int getNumberOfPages() const;
    void setNumberOfPages(int value);
    int getCost() const;
    void setCost(int value);
    QString getUniqueCode() const;
    void setUniqueCode(int value);
};


inline QDataStream &operator<< (QDataStream &ost, const booksinfo &booksinfo)
{
    ost << booksinfo.getBookTitle() << booksinfo.getAuthor() << booksinfo.getNumberOfPages() << booksinfo.getCost() << booksinfo.getUniqueCode();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, booksinfo &booksinfo)
{
    QString bookTitle;
    QString author;
    int numberOfPages;
    int cost;
    QString uniqueCode;

    ist >> bookTitle >> author >> numberOfPages >> cost >> uniqueCode;
    booksinfo.setData(bookTitle, author, numberOfPages, cost, uniqueCode);
    return ist;
}
#endif // BOOKSINFO_H
