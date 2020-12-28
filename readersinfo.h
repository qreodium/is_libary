#ifndef READERSINFO_H
#define READERSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>


class readersinfo
{
private:
    QString lastName;
    QString firstName;
    QString patronymic;
    int readerNumber;
    QString homeAddress;
    QString login;
    QString password;
public:
    readersinfo();
    readersinfo(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password);
    void setData(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password);
    QString getLastName() const;
    void setLastName(const QString &value);
    QString getFirstName() const;
    void setFirstName(const QString &value);
    QString getPatronymic() const;
    void setPatronymic(const QString &value);
    int getReaderNumber() const;
    void setReaderNumber(int value);
    QString getHomeAddress() const;
    void setHomeAddress(const QString &value);
    QString getLogin() const;
    void setLogin(const QString &value);
    QString getPassword() const;
    void setPassword(const QString &value);
};


inline QDataStream &operator<< (QDataStream &ost, const readersinfo &readers)
{
    ost << readers.getLastName() << readers.getFirstName() << readers.getPatronymic() <<
           readers.getReaderNumber() << readers.getHomeAddress()<< readers.getLogin() << readers.getPassword();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, readersinfo &readers)
{
    QString lastName;
    QString firstName;
    QString patronymic;
    int readerNumber;
    QString homeAddress;
    QString login;
    QString password;

    ist >> lastName >> firstName >> patronymic >> readerNumber >> homeAddress >> login >> password;
    readers.setData(lastName, firstName ,patronymic ,readerNumber ,homeAddress ,login ,password);
    return ist;
}

#endif // READERSINFO_H
