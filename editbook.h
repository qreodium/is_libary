#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QDialog>

namespace Ui {
class editBook;
}

class editBook : public QDialog
{
    Q_OBJECT

public:
    explicit editBook(QWidget *parent = nullptr);
    ~editBook();
    int getResult();

private slots:
    void clickedFirst();
    void clickedSecond();
    void clickedThird();

private:
    int numberButton;
    Ui::editBook *ui;
};

#endif // EDITBOOK_H
