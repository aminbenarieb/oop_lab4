#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

static const int kProcessDoorTime = 2000;
static const int kProcessFloorTime = 1000;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    manager(kProcessDoorTime, kProcessFloorTime)
{
    ui->setupUi(this);

    connect(this, SIGNAL(floorNumberChanged(int)), &manager, SLOT(setFloor(int)));

    connect(&(manager.getElevator()), SIGNAL(floorChanged(int)), this, SLOT(setFloorNumber(int)));
    connect(&(manager.getElevator().getDoors()), SIGNAL(stateChanged(DoorState)), this, SLOT(setDoorState(DoorState)));
    connect(&(manager.getElevator()), SIGNAL(directionChanged(ElevatorDirection)), this, SLOT(setDirection(ElevatorDirection)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFloorNumber(int floorNumber)
{
    qDebug()<<QString("Moved to floor: %1").arg(floorNumber);
}
void MainWindow::setDirection(ElevatorDirection elevatorDirection)
{
    switch(elevatorDirection)
    {
        case DIRECTION_UP:
            qDebug()<<"Getting up...";
            break;
        case DIRECTION_DOWN:
            qDebug()<<"Getting down...";
            break;
        default:
            qDebug()<<"Elevator is stopped.";
            break;
    }
}
void MainWindow::setDoorState(DoorState doorState)
{
    switch(doorState)
    {
        case DOOR_OPEN:
            qDebug()<<"Door is opened.";
            break;
        case DOOR_OPENING:
            qDebug()<<"Door is opening.";
            break;
        case DOOR_CLOSING:
            qDebug()<<"Door is closing.";
            break;
        case DOOR_CLOSED:
            qDebug()<<"Door is closed.";
            break;
        default:
            break;
    }
}

void MainWindow::on_btnFloor1_clicked()
{
    emit floorNumberChanged(1);
}
void MainWindow::on_btnFloor2_clicked()
{
    emit floorNumberChanged(2);
}
void MainWindow::on_btnFloor3_clicked()
{
    emit floorNumberChanged(3);
}
void MainWindow::on_btnFloor4_clicked()
{
    emit floorNumberChanged(4);
}
