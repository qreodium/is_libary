#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class authentication;
}

//!
//! \brief Класс авторизации в системе
//!
class authentication : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit authentication(QWidget *parent = nullptr);
    //! Деструктор
    ~authentication();

private slots:
    //!
    //! \brief Слот для проверки пароля
    //!
    void checkPassword();

private:
    Ui::authentication *ui;
    MainWindow *mui;

};

#endif // AUTHENTICATION_H
