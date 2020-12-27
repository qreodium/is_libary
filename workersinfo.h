#ifndef WORKERSINFO_H
#define WORKERSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>

class workersinfo
{
private:
    QString lastName;
    QString firstName;
    QString patronymic;
    bool administrator;
    QString homeAddress;
    QString login;
    QString password;
public:
    workersinfo();
    workersinfo(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password);
    void setData(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password);
    QString getLastName() const;
    void setLastName(const QString &value);
    QString getFirstName() const;
    void setFirstName(const QString &value);
    QString getPatronymic() const;
    void setPatronymic(const QString &value);
    bool getAdministrator() const;
    void setAdministrator(bool value);
    QString getHomeAddress() const;
    void setHomeAddress(const QString &value);
    QString getLogin() const;
    void setLogin(const QString &value);
    QString getPassword() const;
    void setPassword(const QString &value);
};


inline QDataStream &operator<< (QDataStream &ost, const workersinfo &workers)
{
    ost << workers.getLastName() << workers.getFirstName() << workers.getPatronymic() <<
           workers.getAdministrator() << workers.getHomeAddress()<< workers.getLogin() << workers.getPassword();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, workersinfo &workers)
{
    QString lastName;
    QString firstName;
    QString patronymic;
    bool administrator;
    QString homeAddress;
    QString login;
    QString password;

    ist >> lastName >> firstName >> patronymic >> administrator >> homeAddress >> login >> password;
    workers.setData(lastName, firstName ,patronymic ,administrator ,homeAddress ,login ,password);
    return ist;
}

#endif // WORKERSINFO_H
