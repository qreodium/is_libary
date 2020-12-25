#include "database.h"
#include "config.h"

database::database(QWidget *parent) : QMainWindow(parent)
{
    book->saveInfo(0);
    book_new->loadInfo(0);
    book_new->saveInfo(1);
}

int database::test()
{
    return 228;
}
