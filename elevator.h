#ifndef ELEVATORT_H
#define ELEVATORT_H

#include <QObject>
#include "doors.h"

enum ElevatorState{
    ELEVATOR_STAY,
    ELEVATOR_MOVE,
    ELEVATOR_OPENING,
    ELEVATOR_OPENED,
    ELEVATOR_CLOSING,
    ELEVATOR_CLOSED
};

enum ElevatorDirection
{
    ELEVATORDIRECTION_NONE,
    DIRECTION_UP,
    DIRECTION_DOWN
};



class Elevator : public QObject
{
public:
    Elevator(int,int);

    Doors& getDoors();
    ElevatorState getState() const;

    int getTargetFloorNumber() const;
    void setTargetFloorNumber(int);

public slots:
    void processFloor(int);
    void monitor();
    void foo();


signals:

private:
    Doors doors;
    ElevatorState state = ELEVATOR_STAY;
    int currentFloorNumber;
    int targetFloorNumber;

};

#endif // ELEVATORT_H
