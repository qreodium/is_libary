#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include "workersinfo.h"
#include "readersinfo.h"

namespace Ui {
class newuser;
}

class newuser : public QDialog
{
    Q_OBJECT

public:
    explicit newuser(QWidget *parent = nullptr);
    ~newuser();
    void deliverUserRank(int value);
    readersinfo createReaders();
    workersinfo createWorkers();
    int isWorker();


private:
    Ui::newuser *ui;
};

#endif // NEWUSER_H
