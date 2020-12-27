#include "workersinfo.h"

workersinfo::workersinfo()
{

}

workersinfo::workersinfo(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password)
{
    lastName=_lastName;
    firstName=_firstName;
    patronymic = _patronymic;
    administrator=_administrator;
    homeAddress =_homeAddress;
    login =_login;
    password =_password;
}


void workersinfo::setData(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password)
{
    lastName=_lastName;
    firstName=_firstName;
    patronymic = _patronymic;
    administrator=_administrator;
    homeAddress =_homeAddress;
    login =_login;
    password =_password;
}

QString workersinfo::getLastName() const
{
    return lastName;
}

void workersinfo::setLastName(const QString &value)
{
    lastName = value;
}

QString workersinfo::getFirstName() const
{
    return firstName;
}

void workersinfo::setFirstName(const QString &value)
{
    firstName = value;
}

QString workersinfo::getPatronymic() const
{
    return patronymic;
}

void workersinfo::setPatronymic(const QString &value)
{
    patronymic = value;
}

bool workersinfo::getAdministrator() const
{
    return administrator;
}

void workersinfo::setAdministrator(bool value)
{
    administrator = value;
}

QString workersinfo::getHomeAddress() const
{
    return homeAddress;
}

void workersinfo::setHomeAddress(const QString &value)
{
    homeAddress = value;
}

QString workersinfo::getLogin() const
{
    return login;
}

void workersinfo::setLogin(const QString &value)
{
    login = value;
}

QString workersinfo::getPassword() const
{
    return password;
}

void workersinfo::setPassword(const QString &value)
{
    password = value;
}
