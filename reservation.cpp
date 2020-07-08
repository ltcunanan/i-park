#include "login.h"
#include "reservation.h"
#include "ui_reservation.h"
#include <QMessageBox>
#include <status.h>
#include <main_interface.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>

Reservation::Reservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Lilian C/Documents/qtworkspace/128v3/128v03/images/wait.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    QString one = "lcdNumber";
    QString two = "lcdNumber_2";

    lCDNumber2 = Reservation::findChild<QLCDNumber *>(one);
    lCDNumber3 = Reservation::findChild<QLCDNumber *>(two);

    updatetimer = new QTimer(this);
    initial();

    connect(updatetimer, SIGNAL(timeout()), this, SLOT(update()));
}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::status(){
    QSqlQuery qry;
    QString user, spot;

    qry.prepare("select user_ID from User where user_status = 1");
    qry.exec();
    qry.next();
    user = qry.value(0).toString();

    qry.prepare("select spot_ID from Orderr where user_ID = '"+user+"' ");
    qry.exec();
    qry.next();
    spot = qry.value(0).toString();

    qry.exec("update Spot set spot_status = 1 where spot_ID = '"+spot+"' ");
    qry.exec("update User set user_stat = 1 where user_ID = '"+user+"' ");


    hide();
    Status a;
    a.setModal(true);
    a.setWindowTitle("Status Page");
    a.exec();
}

void Reservation::initial()
{
   updatetimer->start(1000);
   mcount = 19;
   scount = 59;
   lCDNumber2->display(mcount);
   lCDNumber3->display(scount);
}

void Reservation::update()
{
    scount--;
    if(scount<0) {
        scount = 59;
        mcount--;
    }
    if(mcount<0) {
        mcount = 59;
    }
    if(scount == 0 && mcount == 0){
        status();
    }

    lCDNumber2->display(mcount);
    lCDNumber3->display(scount);
}

void Reservation::on_pushButton_clicked() //GO
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Start Time? ",
                    "Are you ready to start the time? <br> Pressing YES would redirect you to the Status Page <br> Reservation fee is 10 pesos", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        status();
    }
}

void Reservation::on_pushButton_2_clicked() //CANCEL
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Cancel Order? ",
                    "Are you sure you want to cancel your order? <br> Pressing NO would redirect you to your Profile Page. <br> Reservation fee of 10 pesos will be deducted from your account.", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        QSqlQuery qry;
        QString user, spot, order, money;
        int c = 0;

        qry.prepare("select user_ID from User where user_status = 1");
        qry.exec();
        qry.next();
        user = qry.value(0).toString();

        qry.prepare("select credit from User where user_status = 1");
        qry.exec();
        qry.next();
        c = qry.value(0).toInt();
        c = c - 10;
        money = QString::number(c);

        qry.prepare("select spot_ID from Orderr where user_ID = '"+user+"' ");
        qry.exec();
        qry.next();
        spot = qry.value(0).toString();

        qry.prepare("select order_ID from Orderr where user_ID = '"+user+"' ");
        qry.exec();
        qry.next();
        order = qry.value(0).toString();

        qry.exec("update Spot set spot_status = 0 where spot_ID = '"+spot+"' "); //Vacant the spot

        qry.exec("update User set credit = '"+money+"' where user_ID = '"+user+"' "); //decrease user's money

        qry.exec("DELETE FROM Orderr WHERE order_ID = '"+order+"' ");

        hide();
        main_interface a;
        a.setModal(true);
        a.setWindowTitle("Profile Page");
        a.exec();
    }

}
