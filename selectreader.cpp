#include "selectreader.h"
#include "ui_selectreader.h"

selectReader::selectReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectReader)
{
    ui->setupUi(this);
}

selectReader::~selectReader()
{
    delete ui;
}

void selectReader::deliverDatabase(database* _db)
{
    db=_db;
    updateTable();
}

void selectReader::updateTable()
{
ui->tableWidget->setRowCount(0);

for(int i = 0; i < db->readers.count(); i++)
{
    ui->tableWidget->insertRow(i);
    QTableWidgetItem *item_userLastName = new QTableWidgetItem(db->readers[i].getLastName());
    QTableWidgetItem *item_userFirstName = new QTableWidgetItem(db->readers[i].getFirstName());
    QTableWidgetItem *item_userPatronymic = new QTableWidgetItem(db->readers[i].getPatronymic());
    QTableWidgetItem *item_userRank = new QTableWidgetItem("Читатель");
    QTableWidgetItem *item_userHomeAddress = new QTableWidgetItem(db->readers[i].getHomeAddress());
    QTableWidgetItem *item_userReaderNumber = new QTableWidgetItem(QString::number(db->readers[i].getReaderNumber()));

    item_userLastName->setData(Qt::UserRole,i);
    ui->tableWidget->setItem(i,0,item_userLastName);
    ui->tableWidget->setItem(i,1,item_userFirstName);
    ui->tableWidget->setItem(i,2,item_userPatronymic);
    ui->tableWidget->setItem(i,3,item_userRank);
    ui->tableWidget->setItem(i,4,item_userHomeAddress);
    ui->tableWidget->setItem(i,5,item_userReaderNumber);
}
}

void selectReader::clickedTable(int row)
{
    readersNumber = ui->tableWidget->item(row, 5)->text().toUInt();
    qDebug() << "select: number:" << ui->tableWidget->item(row, 5)->text();
    this->accept();
}

int selectReader::getReaderNumber()
{
    return readersNumber;
}
