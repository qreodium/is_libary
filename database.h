#ifndef LOADBOOKS_H
#define LOADBOOKS_H

#include <QMainWindow>
#include <booksinfo.h>
#include <workersinfo.h>
#include <readersinfo.h>
#include <rentedinfo.h>
#include <QList>

//!
//! \brief Класс обрабатывающий все данные системы
//!
class database : public QMainWindow
{
    Q_OBJECT


private:


public:
    //!
    //! \brief Переменная, в которой хранится должность текущего пользователя
    //!
    int userRank = 0;
    //! Структура, содержащая информацию о всех книгах
    QList<booksinfo> books;
    //! Структура, содержащая информацию о всех работниках
    QList<workersinfo> workers;
    //! Структура, содержащая информацию о всех читателях
    QList<readersinfo> readers;
    //! Структура, содержащая информацию о всех взятых книгах
    QList<rentedinfo> rented;

    explicit database(QWidget *parent = nullptr);
    //!
    //! \brief Загрузить базу данных из файла, прописанного в config.h
    //!
    void loadBooks();
    //!
    //! \brief Сохраняет базу данных из файла, прописанного в config.h
    //!
    void saveBooks();
    //!
    //! \brief Загрузить базу данных из файла, прописанного в config.h
    //!
    void loadWorkers();
    //!
    //! \brief Сохраняет базу данных из файла, прописанного в config.h
    //!
    void saveWorkers();
    //!
    //! \brief Загрузить базу данных из файла, прописанного в config.h
    //!
    void loadReaders();
    //!
    //! \brief Сохраняет базу данных из файла, прописанного в config.h
    //!
    void saveReaders();
    //!
    //! \brief Загрузить базу данных из файла, прописанного в config.h
    //!
    void loadRented();
    //!
    //! \brief Сохраняет базу данных из файла, прописанного в config.h
    //!
    void saveRented();

};

#endif // LOADBOOKS_H
