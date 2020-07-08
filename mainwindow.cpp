#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reserve.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    reserve a;
    a.setModal(true);
    a.setWindowTitle("Reservation Page");
    a.exec();

}
