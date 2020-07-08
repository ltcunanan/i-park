#include "parkingpopup.h"
#include "ui_parkingpopup.h"

parkingPopUp::parkingPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parkingPopUp)
{
    ui->setupUi(this);
}

parkingPopUp::~parkingPopUp()
{
    delete ui;
}
