#include "manager.h"

#include <QTimer>

Manager::Manager(int processDoorVal, int processFloorVal) : elevator(processDoorVal, processFloorVal){

    connect(&elevator, SIGNAL(floorCompleted()), this, SLOT(monitorStandingLift()));
    connect(this, SIGNAL(getCommand()), this, SLOT(monitorStandingLift()));
    connect(this, SIGNAL(elevatorMoved()), &elevator, SLOT(move()));
    connect(&elevator, SIGNAL(floorChanged(int)), this, SLOT(monitorMovingLift(int)));
    connect(this, SIGNAL(elevatorStant()), &elevator, SLOT(standWithOpeningDoors()));
}

void Manager::setFloor(int floorNumber)
{
    floorList.push_back(floorNumber);
    emit getCommand();
}
void Manager::monitorStandingLift()
{
    if ((this->elevator.getState() == ELEVATOR_STANDING) && floorList.size() > 0)
    {
        int targetFloor = floorList.first();
        floorList.pop_front();
        elevator.setTargetFloorNumber(targetFloor);

        emit elevatorMoved();
    }
}
void Manager::monitorMovingLift(int floorNumber)
{
    if ((elevator.getState() == ELEVATOR_MOVING))
    {
        if ( floorNumber != elevator.getTargetFloorNumber() )
        {
            QTimer::singleShot(elevator.getProcessFloorTime(), &elevator, SLOT(move()));
        }
        else
        {
            emit elevatorStant();
        }
    }
}

Elevator& Manager::getElevator()
{
    return this->elevator;
}
