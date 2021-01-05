#ifndef WORKERSINFO_H
#define WORKERSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>
//!
//! \brief Класс для хранения информации о работниках
//!
class workersinfo
{
private:
    //!
    //! \brief lastName
    //!
    QString lastName;
    //!
    //! \brief firstName
    //!
    QString firstName;
    //!
    //! \brief patronymic
    //!
    QString patronymic;
    //!
    //! \brief administrator
    //!
    bool administrator;
    //!
    //! \brief homeAddress
    //!
    QString homeAddress;
    //!
    //! \brief login
    //!
    QString login;
    //!
    //! \brief password
    //!
    QString password;
public:
    //! Конструктор
    workersinfo();
    //! Конструктор
    workersinfo(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password);
    //!
    //! \brief setData
    //! \param _lastName
    //! \param _firstName
    //! \param _patronymic
    //! \param _administrator
    //! \param _homeAddress
    //! \param _login
    //! \param _password
    //!
    void setData(QString _lastName, QString _firstName, QString _patronymic, bool _administrator, QString _homeAddress, QString _login, QString _password);
    //!
    //! \brief getLastName
    //! \return
    //!
    QString getLastName() const;
    //!
    //! \brief setLastName
    //! \param value
    //!
    void setLastName(const QString &value);
    //!
    //! \brief getFirstName
    //! \return
    //!
    QString getFirstName() const;
    //!
    //! \brief setFirstName
    //! \param value
    //!
    void setFirstName(const QString &value);
    //!
    //! \brief getPatronymic
    //! \return
    //!
    QString getPatronymic() const;
    //!
    //! \brief setPatronymic
    //! \param value
    //!
    void setPatronymic(const QString &value);
    //!
    //! \brief getAdministrator
    //! \return
    //!
    bool getAdministrator() const;
    //!
    //! \brief setAdministrator
    //! \param value
    //!
    void setAdministrator(bool value);
    //!
    //! \brief getHomeAddress
    //! \return
    //!
    QString getHomeAddress() const;
    //!
    //! \brief setHomeAddress
    //! \param value
    //!
    void setHomeAddress(const QString &value);
    //!
    //! \brief getLogin
    //! \return
    //!
    QString getLogin() const;
    //!
    //! \brief setLogin
    //! \param value
    //!
    void setLogin(const QString &value);
    //!
    //! \brief getPassword
    //! \return
    //!
    QString getPassword() const;
    //!
    //! \brief setPassword
    //! \param value
    //!
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
