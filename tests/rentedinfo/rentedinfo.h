#ifndef RENTEDINFO_H
#define RENTEDINFO_H

#include <QString>
#include <QDate>
#include <QDataStream>
#include <QDebug>


class rentedinfo
{
private:
    QString uniqueCode;
    int readerNumber;
    QDate start;
    QDate end;

public:
    rentedinfo();
    rentedinfo(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end);
    void setData(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end);
    QString getUniqueCode() const;
    void setUniqueCode(const QString &value);
    int getReaderNumber() const;
    void setReaderNumber(int value);
    QDate getStart() const;
    void setStart(const QDate &value);
    QDate getEnd() const;
    void setEnd(const QDate &value);
};



inline QDataStream &operator<< (QDataStream &ost, const rentedinfo &rentedinfo)
{
    ost << rentedinfo.getUniqueCode() << rentedinfo.getReaderNumber() << rentedinfo.getStart() << rentedinfo.getEnd();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, rentedinfo &rentedinfo)
{
    QString uniqueCode;
    int readerNumber;
    QDate start;
    QDate end;

    ist >> uniqueCode >> readerNumber >> start >> end;
    rentedinfo.setData(uniqueCode, readerNumber, start, end);
    return ist;
}
#endif // RENTEDINFO_H
