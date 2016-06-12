#ifndef ELEVATORT_H
#define ELEVATORT_H

#include <QObject>

#include "doors.h"

enum ElevatorState{
    ELEVATOR_STANDING,
    ELEVATOR_MOVING,
    ELEVATOR_OPENING,
    ELEVATOR_OPENED,
    ELEVATOR_CLOSING,
    ELEVATOR_CLOSED
};

enum ElevatorDirection
{
    DIRECTION_NONE,
    DIRECTION_UP,
    DIRECTION_DOWN
};

class InvalidElevatorCommand : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Invalid elevator state translation.";
    }
};



class Elevator : public QObject
{
    Q_OBJECT

public:
    Elevator(int,int);

    Doors& getDoors();
    ElevatorState getState() const;

    int getTargetFloorNumber() const;
    void setTargetFloorNumber(int);

    int getProcessFloorTime() const;

public slots:
    void move();
    void stand();
    void standWithOpeningDoors();
    void standWithOpenedDoors();
    void standWithClosingDoors();

signals:
    void floorChanged(int);
    void directionChanged(ElevatorDirection);

    void floorCompleted();

    void readyToOpenDoors();
    void readyToCloseDoors();



private:
    Doors doors;
    ElevatorState state = ELEVATOR_STANDING;
    int currentFloorNumber = 1;
    int targetFloorNumber;
    int processFloorTime;
    int processDoorTime;

};

#endif // ELEVATORT_H
