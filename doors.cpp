#include "doors.h"
#include <QTimer>

Doors::Doors(int processTimeVal): processTime(processTimeVal) {}

DoorState Doors::getState() const
{
    return state;
}

void Doors::opening()
{
    if (this->state != DOOR_CLOSED)
        throw InvalidDoorCommand();

    this->state = DOOR_OPENING;
    emit stateChanged(this->state);
    QTimer::singleShot(this->processTime, this, SLOT(open()));
}
void Doors::open()
{
    if (this->state != DOOR_OPENING)
        throw InvalidDoorCommand();

    this->state = DOOR_OPEN;
    emit stateChanged(this->state);
    emit doorOpened();
}
void Doors::closing()
{
    if (this->state != DOOR_OPEN)
        throw InvalidDoorCommand();

    this->state = DOOR_CLOSING;
    emit stateChanged(this->state);
    QTimer::singleShot(this->processTime, this, SLOT(close()));
}
void Doors::close()
{
    if (this->state != DOOR_CLOSING)
        throw InvalidDoorCommand();

    this->state = DOOR_CLOSED;
    emit stateChanged(this->state);
    emit doorClosed();
}
