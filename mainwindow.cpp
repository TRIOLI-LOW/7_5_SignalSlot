#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatchWindow = new Dialog(this);

    connect(ui->push, &QPushButton::clicked, this, &MainWindow::pushClicked);

}

    void MainWindow::pushClicked(){

    stopwatchWindow->show();
    }

MainWindow::~MainWindow()
{
    delete ui;

}





