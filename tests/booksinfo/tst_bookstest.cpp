#include <QtTest>
#include "booksinfo.h"

// add necessary includes here

class bookstest : public QObject
{
    Q_OBJECT

public:
    bookstest();
    ~bookstest();

private slots:
    void test_getBookTitle();
    void test_getAuthor();
    void test_getNumberOfPages();
    void test_getCost();
    void test_getUniqueCode();

};

bookstest::bookstest()
{

}

bookstest::~bookstest()
{

}

void bookstest::test_getBookTitle()
{
    booksinfo book("Zagolovok", "Avtor", 39042782, 8999, "code928i10905");
    QCOMPARE(book.getBookTitle(), "Zagolovok");
}
void bookstest::test_getAuthor()
{
    booksinfo book("Zagolovok", "Avtor", 39042782, 8999, "code928i10905");
    QCOMPARE(book.getAuthor(), "Avtor");
}
void bookstest::test_getNumberOfPages()
{
    booksinfo book("Zagolovok", "Avtor", 39042782, 8999, "code928i10905");
    QCOMPARE(book.getNumberOfPages(), 39042782);
}
void bookstest::test_getCost()
{
    booksinfo book("Zagolovok", "Avtor", 39042782, 8999, "code928i10905");
    QCOMPARE(book.getCost(), 8999);
}
void bookstest::test_getUniqueCode()
{
    booksinfo book("Zagolovok", "Avtor", 39042782, 8999, "code928i10905");
    QCOMPARE(book.getUniqueCode(), "code928i10905");
}

QTEST_APPLESS_MAIN(bookstest)

#include "tst_bookstest.moc"
