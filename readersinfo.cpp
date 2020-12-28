#include "readersinfo.h"

readersinfo::readersinfo()
{

}

readersinfo::readersinfo(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password)
{
    lastName=_lastName;
    firstName=_firstName;
    patronymic = _patronymic;
    readerNumber=_readerNumber;
    homeAddress =_homeAddress;
    login =_login;
    password =_password;
}


void readersinfo::setData(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password)
{
    lastName=_lastName;
    firstName=_firstName;
    patronymic = _patronymic;
    readerNumber=_readerNumber;
    homeAddress =_homeAddress;
    login =_login;
    password =_password;
}


QString readersinfo::getLastName() const
{
    return lastName;
}

void readersinfo::setLastName(const QString &value)
{
    lastName = value;
}

QString readersinfo::getFirstName() const
{
    return firstName;
}

void readersinfo::setFirstName(const QString &value)
{
    firstName = value;
}

QString readersinfo::getPatronymic() const
{
    return patronymic;
}

void readersinfo::setPatronymic(const QString &value)
{
    patronymic = value;
}

int readersinfo::getReaderNumber() const
{
    return readerNumber;
}

void readersinfo::setReaderNumber(int value)
{
    readerNumber = value;
}

QString readersinfo::getHomeAddress() const
{
    return homeAddress;
}

void readersinfo::setHomeAddress(const QString &value)
{
    homeAddress = value;
}

QString readersinfo::getLogin() const
{
    return login;
}

void readersinfo::setLogin(const QString &value)
{
    login = value;
}

QString readersinfo::getPassword() const
{
    return password;
}

void readersinfo::setPassword(const QString &value)
{
    password = value;
}
