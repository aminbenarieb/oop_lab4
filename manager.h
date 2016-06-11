#ifndef MANAGER_H
#define MANAGER_H

#include <QList>

#include "elevator.h"

class Manager : public QObject
{
    Q_OBJECT

public:
    Manager(int, int);

public slots:
    void setFloor(int);

signals:


private:
    Elevator elevator;
    QList <int> floorList;
};

// получаем
// думает check - monitor
// мониторит


#endif // MANAGER_H
