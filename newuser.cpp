#include "newuser.h"
#include "ui_newuser.h"

newuser::newuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newuser)
{
    ui->setupUi(this);

}

newuser::~newuser()
{
    delete ui;
    ui->comboBox->setDisabled(false);
}

void newuser::deliverUserRank(int value)
{
    if (value != 2)
        ui->comboBox->setDisabled(true);
}

readersinfo newuser::createReaders()
{
    readersinfo user(ui->lineEditLastName->text(),ui->lineEditFirstName->text(),
                     ui->lineEditPatronymic->text(),ui->spinBoxReaderNumber->text().toUInt(),ui->lineEditHome->text(),ui->lineEditLogin->text(),ui->lineEditPassword->text());
    return user;
}

int newuser::isWorker()
{
    return ui->comboBox->currentIndex();
}

workersinfo newuser::createWorkers()
{
    workersinfo user(ui->lineEditLastName->text(),ui->lineEditFirstName->text(),
                     ui->lineEditPatronymic->text(),ui->comboBox->currentIndex()-1,ui->lineEditHome->text(),ui->lineEditLogin->text(),ui->lineEditPassword->text());
    return user;
}
