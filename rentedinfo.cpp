#include "rentedinfo.h"

rentedinfo::rentedinfo(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end)
{
    uniqueCode=_uniqueCode;
    readerNumber=_readerNumber;
    start = _start;
    end=_end;
}


void rentedinfo::setData(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end)
{
    uniqueCode=_uniqueCode;
    readerNumber=_readerNumber;
    start = _start;
    end=_end;
}

QString rentedinfo::getUniqueCode() const
{
    return uniqueCode;
}

void rentedinfo::setUniqueCode(const QString &value)
{
    uniqueCode = value;
}

int rentedinfo::getReaderNumber() const
{
    return readerNumber;
}

void rentedinfo::setReaderNumber(int value)
{
    readerNumber = value;
}

QDate rentedinfo::getStart() const
{
    return start;
}

void rentedinfo::setStart(const QDate &value)
{
    start = value;
}

QDate rentedinfo::getEnd() const
{
    return end;
}

void rentedinfo::setEnd(const QDate &value)
{
    end = value;
}

rentedinfo::rentedinfo()
{

}
