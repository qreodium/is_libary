#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "booksinfo.h"
#include "database.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//!
//! \brief Класс главного окна программы
//!
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Конструктор
    MainWindow(QWidget *parent = nullptr);
    //! Деструктор
    ~MainWindow();
    //!
    //! \brief Передача указателя на базу данных
    //! \param _db
    //!
    void deliveryDatabase(database* _db);
private:
    //!
    //! \brief Переменная хранящая ссылку на текущую базу данных
    //!
    database* db;
    //!
    //! \brief Метод для обновления данных
    //!
    //!  Метод для обновления данных записанных в таблице согласно данным из базы данных
    //!
    void updateTables();

private slots:
    //!
    //! \brief updated
    //!
    void updated();
    //!
    //! \brief clickedTablePeople
    //! \param row
    //!
    void clickedTablePeople(int row);
    //!
    //! \brief clickedTableBook
    //! \param row
    //!
    void clickedTableBook(int row);
    //!
    //! \brief createNewBook
    //!
    void createNewBook();
    //!
    //! \brief createNewUser
    //!
    void createNewUser();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
