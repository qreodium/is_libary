#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QDialog>

namespace Ui {
class editBook;
}

//!
//! \brief Класс для изменения книги
//!
class editBook : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit editBook(QWidget *parent = nullptr);
    //! Деструктор
    ~editBook();
    //!
    //! \brief getResult
    //! \return
    //!
    int getResult();

private slots:
    //!
    //! \brief clickedFirst
    //!
    void clickedFirst();
    //!
    //! \brief clickedSecond
    //!
    void clickedSecond();
    //!
    //! \brief clickedThird
    //!
    void clickedThird();

private:
    //!
    //! \brief numberButton
    //!
    int numberButton;
    Ui::editBook *ui;
};

#endif // EDITBOOK_H
