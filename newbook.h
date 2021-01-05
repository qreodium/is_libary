#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <QDialog>
#include "booksinfo.h"
#include "mainwindow.h"



namespace Ui {
class newBook;
}
//!
//! \brief Класс для создания новой книги
//!
class newBook : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit newBook(QWidget *parent = nullptr);
    //! Деструктор
    ~newBook();
    //!
    //! \brief Создает экземпляр книги использую данные из соответвующего окна
    //! \return
    //!
    booksinfo create();

private:
    Ui::newBook *ui;
};

#endif // NEWBOOK_H
