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
    QString message = QString("Moved to floor: %1").arg(floorNumber);;
    qDebug()<<message;
    this->ui->FloorLabel->setText(message);
}
void MainWindow::setDirection(ElevatorDirection elevatorDirection)
{
    QString message;
    switch(elevatorDirection)
    {
        case DIRECTION_UP:
            message = "Getting up...";
            break;
        case DIRECTION_DOWN:
            message = "Getting down...";
            break;
        default:
            message = "Elevator is stopped.";
            break;
    }
    qDebug()<<message;
    this->ui->statusLabel->setText(message);
}
void MainWindow::setDoorState(DoorState doorState)
{
    QString message;
    switch(doorState)
    {
        case DOOR_OPEN:
            message = "Door is opened.";
            break;
        case DOOR_OPENING:
            message = "Door is opening.";
            break;
        case DOOR_CLOSING:
            message = "Door is closing.";
            break;
        case DOOR_CLOSED:
            message = "Door is closed.";
            break;
        default:
            break;
    }
    qDebug()<<message;
    this->ui->doorLabel->setText(message);
}

void MainWindow::on_btnFloor1_clicked()
{
    try
    {
        emit floorNumberChanged(1);
    }
    catch (std::exception& e)
    {
        this->ui->statusLabel->setText( QString("Status: %1").arg(e.what()) );
    }
}
void MainWindow::on_btnFloor2_clicked()
{
    try
    {
        emit floorNumberChanged(2);
    }
    catch (std::exception& e)
    {
        this->ui->statusLabel->setText( QString("Status: %1").arg(e.what()) );
    }
}
void MainWindow::on_btnFloor3_clicked()
{
    try
    {
        emit floorNumberChanged(3);
    }
    catch (std::exception& e)
    {
        this->ui->statusLabel->setText( QString("Status: %1").arg(e.what()) );
    }
}
void MainWindow::on_btnFloor4_clicked()
{
    try
    {
        emit floorNumberChanged(4);
    }
    catch (std::exception& e)
    {
        this->ui->statusLabel->setText( QString("Status: %1").arg(e.what()) );
    }
}
