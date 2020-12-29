#ifndef SELECTREADER_H
#define SELECTREADER_H

#include <QDialog>
#include "database.h"

namespace Ui {
class selectReader;
}

class selectReader : public QDialog
{
    Q_OBJECT

public:
    explicit selectReader(QWidget *parent = nullptr);
    ~selectReader();
    void deliverDatabase(database* db);
    void updateTable();
    int getReaderNumber();

private slots:
    void clickedTable(int row);

private:
    database* db;
    int readersNumber;
    Ui::selectReader *ui;
};

#endif // SELECTREADER_H
