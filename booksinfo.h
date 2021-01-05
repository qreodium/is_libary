#ifndef BOOKSINFO_H
#define BOOKSINFO_H

#include <QString>
#include <QDataStream>
#include <QDebug>

//!
//! \brief Класс для хранения данных о книгах
//!
class booksinfo
{
private:
    //! Заголовок книги
    QString bookTitle;
    //! Автор книги
    QString author;
    //! Количество страниц
    int numberOfPages;
    //! Стоимость книги
    int cost;
    //! Уникальный код
    QString uniqueCode;
public:
    //! Конструктор
    booksinfo();
    //! Конструктор
    booksinfo(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode);
    //!
    //! \brief Записать все данные для экземпляра класса
    //! \param _bookTitle
    //! \param _author
    //! \param _numberOfPages
    //! \param _cost
    //! \param _uniqueCode
    //!
    void setData(QString _bookTitle, QString _author, int _numberOfPages, int _cost, QString _uniqueCode);
    //!
    //! \brief getBookTitle
    //! \return
    //!
    QString getBookTitle() const;
    //!
    //! \brief setBookTitle
    //! \param value
    //!
    void setBookTitle(const QString &value);
    //!
    //! \brief getAuthor
    //! \return
    //!
    QString getAuthor() const;
    //!
    //! \brief setAuthor
    //! \param value
    //!
    void setAuthor(const QString &value);
    //!
    //!//! \brief getNumberOfPages
    //!//! \return
    //!
    int getNumberOfPages() const;
    //!
    //! \brief setNumberOfPages
    //! \param value
    //!
    void setNumberOfPages(int value);
    //!
    //! \brief getCost
    //! \return
    //!
    int getCost() const;
    //!
    //! \brief setCost
    //! \param value
    //!
    void setCost(int value);
    //!
    //! \brief getUniqueCode
    //! \return
    //!
    QString getUniqueCode() const;
    //!
    //! \brief setUniqueCode
    //! \param value
    //!
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
