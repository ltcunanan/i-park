#include "login.h"
#include "parking.h"
#include "ui_parking.h"
#include "reservation.h"
#include "login.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <algorithm>


parking::parking(QWidget *parent):
    QDialog(parent),
    ui(new Ui::parking)
{
    QSqlQuery qry;

    ui->setupUi(this);

    QPushButton *buttons[25];
    QPalette pal;

    int green[30], red[30];
    bool yesg, yesr;
    int g = 0, num=100;
    QString buts;

    qry.setForwardOnly(true);
    qry.exec("select spot_ID from Spot where spot_status = 0");

    for(; qry.next(); g++){
        green[g] = qry.value(0).toInt();
    }
    //QMessageBox::warning(this, "UPDATE SUCCESS", "NOT ALL GREEN"+g);

    if(g < 25){
        qry.exec("select spot_ID from Spot where spot_status = 1");

        for(int x=0; qry.next(); x++){
            red[x] = qry.value(0).toInt();
        }
    }

    for(int i=0, but1=0;i<25;++i,++num){
        QString butName = "ParkSpace" + QString::number(num);
        buttons[i] = parking::findChild<QPushButton *>(butName);
        buts = buttons[i]->text();
        but1 = buts.toInt();
        yesg = std::find(std::begin(green), std::end(green), but1) != std::end(green);
        if(yesg == true){
            pal = buttons[i]->palette();
            pal.setColor(QPalette::Button, QColor(Qt::green));
            buttons[i]->setAutoFillBackground(true);
            buttons[i]->setPalette(pal);
            buttons[i]->update();
        }
        else{
            yesr = std::find(std::begin(red), std::end(red), but1) != std::end(red);
            if(yesr == true){
                pal = buttons[i]->palette();
                pal.setColor(QPalette::Button, QColor(Qt::red));
                buttons[i]->setAutoFillBackground(true);
                buttons[i]->setPalette(pal);
                buttons[i]->update();
            }
            else{
                pal = buttons[i]->palette();
                pal.setColor(QPalette::Button, QColor(Qt::yellow));
                buttons[i]->setAutoFillBackground(true);
                buttons[i]->setPalette(pal);
                buttons[i]->update();
            }
        }
    }

}

parking::~parking()
{
    delete ui;
}

void parking::ButtonPressed(QString but){

QSqlQuery qry, qry1;
int n=0;
//QString but = button->text();
QString user;
    QMessageBox::StandardButton reply = QMessageBox::question(this, "SPOT "+ but,
                    "Do you want to reserve this spot?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        //check

        qry.prepare("select user_ID from User where user_status = 1");
        qry.exec();
        qry.next();
        user = qry.value(0).toString();

        qry.prepare("select spot_status from Spot where spot_ID ='"+but+"' ");
        qry.exec();
        qry.next();
        n = qry.value(0).toInt();

        if(n == 0)//true : then someone is on the spot
        {
            qry.exec("INSERT INTO Orderr (order_ID, user_ID, spot_ID, date) "
                       "VALUES (null, '"+user+"','"+but+"', null)");

            qry.exec("update Spot set spot_status = 3 where spot_ID = '"+but+"'");

            QMessageBox::information(this, "SUCCESS", "You've successfully claimed this spot.");

            hide();
            Reservation b;
            b.setModal(true);
            b.setWindowTitle("Reservation Page");
            b.exec();

        }

        else if(n == 1)//no one is using the spot
        {
            QMessageBox::warning(this, "Error", "Someone's already using this spot");
        }
        else{
            QMessageBox::warning(this, "Error", "This spot is reserved");
        }
    }
}



void parking::on_ParkSpace100_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);

}

void parking::on_ParkSpace101_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace102_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace103_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace104_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace105_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace106_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace107_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace108_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace109_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace110_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace111_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace112_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace113_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace114_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace115_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace116_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace117_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace118_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}


void parking::on_ParkSpace119_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace120_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace121_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace122_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace123_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}

void parking::on_ParkSpace124_clicked()
{
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text();
    ButtonPressed(buttonText);
}
