#include "elevator.h"

Elevator::Elevator(int processDoorVal, int) : doors(processDoorVal)
{

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
