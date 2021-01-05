#ifndef RENTEDINFO_H
#define RENTEDINFO_H

#include <QString>
#include <QDate>
#include <QDataStream>
#include <QDebug>

//! Класс для хранения информации о арендованных книгах
class rentedinfo
{
private:
    //!
    //! \brief uniqueCode
    //!
    QString uniqueCode;
    //!
    //! \brief readerNumber
    //!
    int readerNumber;
    //!
    //! \brief start
    //!
    QDate start;
    //!
    //! \brief end
    //!
    QDate end;

public:
    //! Конструктор
    rentedinfo();
    //! Конструктор
    rentedinfo(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end);
    //!
    //! \brief setData
    //! \param _uniqueCode
    //! \param _readerNumber
    //! \param _start
    //! \param _end
    //!
    void setData(QString _uniqueCode, int _readerNumber, QDate _start, QDate _end);
    //!
    //! \brief getUniqueCode
    //! \return
    //!
    QString getUniqueCode() const;
    //!
    //! \brief setUniqueCode
    //! \param value
    //!
    void setUniqueCode(const QString &value);
    //!
    //! \brief getReaderNumber
    //! \return
    //!
    int getReaderNumber() const;
    //!
    //! \brief setReaderNumber
    //! \param value
    //!
    void setReaderNumber(int value);
    //!
    //! \brief getStart
    //! \return
    //!
    QDate getStart() const;
    //!
    //! \brief setStart
    //! \param value
    //!
    void setStart(const QDate &value);
    //!
    //! \brief getEnd
    //! \return
    //!
    QDate getEnd() const;
    //!
    //! \brief setEnd
    //! \param value
    //!
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
