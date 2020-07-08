#include "reserve.h"
#include "ui_reserve.h"
#include "spot.h"
#include <QMessageBox>

int status = 0;


reserve::reserve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);

    QPushButton *buttons[25];

    for(int i=0;i<25;++i){
        QString butName = "Button" + QString::number(i);
        buttons[i] = reserve::findChild<QPushButton *>(butName);
        connect(buttons[i],SIGNAL(released()),this,SLOT(ButtonPressed()));
    }

}

reserve::~reserve()
{
    delete ui;
}

void reserve::ButtonPressed(){
    QPushButton *button = (QPushButton *)sender();
    if(status == 0){
        QMessageBox::StandardButton reply = QMessageBox::question(this, "SPOT "+ button->text(),
                        "Do you want to reserve this spot?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            status = 2;
        }
        else{
            status = 0;
        }
    }
    else{
        QMessageBox::warning(this,"SPOT "+ button->text(),"THIS SPOT IS UNAVAILABLE");
    }

}
