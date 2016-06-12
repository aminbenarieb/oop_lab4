#ifndef MANAGER_H
#define MANAGER_H

#include <QList>

#include "elevator.h"

class Manager : public QObject
{
    Q_OBJECT

public:
    Manager(int, int);

    Elevator& getElevator();

public slots:
    void setFloor(int);
    void monitorStandingLift();
    void monitorMovingLift(int);

signals:
    void getCommand();
    void elevatorMoved();
    void elevatorStant();


private:
    Elevator elevator;
    QList <int> floorList;
};



#endif // MANAGER_H
