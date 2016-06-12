#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void setFloorNumber(int);
    void setDirection(ElevatorDirection);
    void setDoorState(DoorState);

signals:
    void floorNumberChanged(int);

private slots:
    void on_btnFloor1_clicked();
    void on_btnFloor2_clicked();
    void on_btnFloor3_clicked();
    void on_btnFloor4_clicked();

private:
    Ui::MainWindow *ui;
    Manager manager;
};

#endif // MAINWINDOW_H
