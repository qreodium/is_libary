#include <QtTest>
#include "rentedinfo.h"
// add necessary includes here

class rentedtest : public QObject
{
    Q_OBJECT

public:
    rentedtest();
    ~rentedtest();

private slots:
    void test_getUniqueCode();
    void test_getReaderNumber();
    void test_getStart();
    void test_getEnd();

};

rentedtest::rentedtest()
{

}

rentedtest::~rentedtest()
{

}

void rentedtest::test_getUniqueCode()
{
    rentedinfo rented("SyV4w",35203,QDate::currentDate(),QDate::currentDate());
    QCOMPARE(rented.getUniqueCode(), "SyV4w");
}

void rentedtest::test_getReaderNumber()
{
    rentedinfo rented("SyV4w",35203,QDate::currentDate(),QDate::currentDate());
    QCOMPARE(rented.getReaderNumber(), 35203);
}

void rentedtest::test_getStart()
{
    rentedinfo rented("SyV4w",35203,QDate::currentDate(),QDate::currentDate());
    QCOMPARE(rented.getStart(), QDate::currentDate());

}

void rentedtest::test_getEnd()
{
    rentedinfo rented("SyV4w",35203,QDate::currentDate(),QDate::currentDate());
    QCOMPARE(rented.getEnd(), QDate::currentDate());
}


QTEST_APPLESS_MAIN(rentedtest)

#include "tst_rentedtest.moc"
