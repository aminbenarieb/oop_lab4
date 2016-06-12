#include "elevator.h"

#include <QTimer>

Elevator::Elevator(int processDoorVal, int processFloorVal) :
    doors(processDoorVal),
    processFloorTime(processFloorVal),
    processDoorTime(processDoorVal)
{
    connect(&doors, SIGNAL(doorOpened()), this, SLOT(standWithOpenedDoors()));
    connect(&doors, SIGNAL(doorClosed()), this, SLOT(stand()));

    connect(this, SIGNAL(readyToOpenDoors()), &doors, SLOT(opening()));
    connect(this, SIGNAL(readyToCloseDoors()), &doors, SLOT(closing()));
}

Doors& Elevator::getDoors()
{
    return doors;
}

ElevatorState Elevator::getState() const
{
    return state;
}

int Elevator::getTargetFloorNumber() const
{
    return targetFloorNumber;
}
void Elevator::setTargetFloorNumber(int value)
{
    targetFloorNumber = value;
}

int Elevator::getProcessFloorTime() const
{
    return processFloorTime;
}


void Elevator::move()
{
    if (state != ELEVATOR_MOVING && state != ELEVATOR_STANDING)
    {
        throw InvalidElevatorCommand();
    }
    state = ELEVATOR_MOVING;

    if (targetFloorNumber > currentFloorNumber)
    {
        emit directionChanged(DIRECTION_UP);
        currentFloorNumber++;
    }
    else if (targetFloorNumber < currentFloorNumber)
    {
        emit directionChanged(DIRECTION_DOWN);
        currentFloorNumber--;
    }

    emit floorChanged(currentFloorNumber);
}
void Elevator::standWithOpeningDoors()
{
    if (state != ELEVATOR_MOVING)
    {
        throw InvalidElevatorCommand();
    }
    state = ELEVATOR_OPENING;

    emit directionChanged(DIRECTION_NONE);
    emit readyToOpenDoors();

}
void Elevator::standWithOpenedDoors()
{
    if (state != ELEVATOR_OPENING)
    {
        throw InvalidElevatorCommand();
    }
    state = ELEVATOR_OPENED;
    QTimer::singleShot(processDoorTime, this, SLOT(standWithClosingDoors()));
}
void Elevator::standWithClosingDoors()
{
    if (state != ELEVATOR_OPENED)
    {
        throw InvalidElevatorCommand();
    }
    state = ELEVATOR_CLOSING;
    emit readyToCloseDoors();
}
void Elevator::stand()
{
    if (state != ELEVATOR_CLOSING)
    {
        throw InvalidElevatorCommand();
    }
    state = ELEVATOR_STANDING;

    emit floorCompleted();

}
