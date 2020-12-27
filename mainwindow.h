#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "booksinfo.h"
#include "database.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void deliveryDatabase(database* _db);
private:
    database* db;
    void updateTableBooks();

private slots:
    void clickedTable(int row, int column);
    void createNewBook();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
