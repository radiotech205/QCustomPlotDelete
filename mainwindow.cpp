#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new MainWidget(this);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}
