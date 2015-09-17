#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"map_panel.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    panel = new MAP_Panel(QRect(0,0,600,400),this);
    panel->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete panel;
}
