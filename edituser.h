#ifndef EDITUSER_H
#define EDITUSER_H

#include <QDialog>

namespace Ui {
class editUser;
}

//!
//! \brief Подтверждение удалениия пользователя
//!
class editUser : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit editUser(QWidget *parent = nullptr);
    //! Дестркутор
    ~editUser();
    //!
    //! \brief getResult
    //! \return
    //!
    int getResult();

private slots:
    //!
    //! \brief clickedThird
    //!
    void clickedThird();

private:
    //!
    //! \brief numberButton
    //!
    int numberButton;
    Ui::editUser *ui;
};

#endif // EDITUSER_H
