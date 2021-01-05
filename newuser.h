#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include "workersinfo.h"
#include "readersinfo.h"

namespace Ui {
class newuser;
}
//!
//! \brief Класс для создания нового пользователя
//!
class newuser : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit newuser(QWidget *parent = nullptr);
    //! Деструктор
    ~newuser();
    //!
    //! \brief deliverUserRank
    //! \param value
    //!
    void deliverUserRank(int value);
    //!
    //! \brief Создает экземпляр читателя использую данные из соответвующего окна
    //! \return
    //!
    readersinfo createReaders();
    //!
    //! \brief Создает экземпляр работника использую данные из соответвующего окна
    //! \return
    //!
    workersinfo createWorkers();
    //!
    //! \brief isWorker
    //! \return
    //!
    int isWorker();


private:
    Ui::newuser *ui;
};

#endif // NEWUSER_H
