#ifndef DOORS_H
#define DOORS_H

#include <QObject>

enum DoorState{
    DOOR_OPENING,
    DOOR_CLOSING,
    DOOR_OPEN,
    DOOR_CLOSED
};

class InvalidDoorCommand : public std::exception
{
public:
    using std::exception::what;
    virtual const char *what() const throw()
    {
        return "Invalid door state translation.";
    }
};

class Doors: public QObject
{
    Q_OBJECT

public:
    Doors(int);

    DoorState getState() const;

public slots:
    void open();
    void opening();
    void close();
    void closing();

signals:
    void stateChanged(DoorState);
    void doorOpened();
    void doorClosed();

private:
    DoorState state = DOOR_CLOSED;
    int processTime;
};

#endif // DOORS_H
