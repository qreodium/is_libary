#ifndef SELECTREADER_H
#define SELECTREADER_H

#include <QDialog>
#include "database.h"

namespace Ui {
class selectReader;
}
//! Выбор читателя
class selectReader : public QDialog
{
    Q_OBJECT

public:
    //! Конструктор
    explicit selectReader(QWidget *parent = nullptr);
    //! Деструктор
    ~selectReader();
    //!
    //! \brief deliverDatabase
    //! \param db
    //!
    void deliverDatabase(database* db);
    //!
    //! \brief updateTable
    //!
    void updateTable();
    //!
    //! \brief getReaderNumber
    //! \return
    //!
    int getReaderNumber();

private slots:
    //!
    //! \brief clickedTable
    //! \param row
    //!
    void clickedTable(int row);

private:
    //!
    //! \brief db
    //!
    database* db;
    //!
    //! \brief readersNumber
    //!
    int readersNumber;
    Ui::selectReader *ui;
};

#endif // SELECTREADER_H
