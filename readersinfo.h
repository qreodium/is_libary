#ifndef READERSINFO_H
#define READERSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>

//! Класс для хранения информации о читателях
class readersinfo
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
    //! \brief readerNumber
    //!
    int readerNumber;
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
    readersinfo();
    //! Конструктор
    readersinfo(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password);
    //!
    //! \brief setData
    //! \param _lastName
    //! \param _firstName
    //! \param _patronymic
    //! \param _readerNumber
    //! \param _homeAddress
    //! \param _login
    //! \param _password
    //!
    void setData(QString _lastName, QString _firstName, QString _patronymic, int _readerNumber, QString _homeAddress, QString _login, QString _password);
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
