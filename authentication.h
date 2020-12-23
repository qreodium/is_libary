#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class authentication;
}

class authentication : public QDialog
{
    Q_OBJECT

public:
    explicit authentication(QWidget *parent = nullptr);
    ~authentication();

private slots:
    void checkPassword();

private:
    Ui::authentication *ui;
    MainWindow *mui;

};

#endif // AUTHENTICATION_H
