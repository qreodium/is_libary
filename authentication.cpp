#include "authentication.h"
#include "ui_authentication.h"

authentication::authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
}

authentication::~authentication()
{
    delete ui;
}


void authentication::checkPassword()
{
    if(ui->line_login->text() == "q")
    {
        hide();
        mui = new MainWindow();
        mui->show();
    }
}
