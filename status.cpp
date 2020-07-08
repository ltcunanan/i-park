#include "status.h"
#include "ui_status.h"
#include <summary.h>
#include <QTimer>
#include <math.h>
#include <QMessageBox>
#include <QString>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

Status::Status(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Lilian C/Documents/qtworkspace/128v3/128v03/images/wait1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QString one = "lcdNumber";
    QString two = "lcdNumber_2";
    QString three = "lcdNumber_3";
    QString four = "lcdNumber_4";

    QSqlQuery qry;
    QString name, spot, user;
    QFont f("Arial",18);

    qry.prepare("select name from User where user_status = 1");
    qry.exec();
    qry.next();
    name = qry.value(0).toString();

    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_4->setFont(f);
    ui->label_4->setText(name);

    qry.prepare("select user_ID from User where user_status = 1");
    qry.exec();
    qry.next();
    user = qry.value(0).toString();

    qry.prepare("select spot_ID from Orderr where user_ID = '"+user+"' ");
    qry.exec();
    qry.next();
    spot = qry.value(0).toString();

    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_5->setFont(f);
    ui->label_5->setText(spot);


    lCDNum1 = Status::findChild<QLCDNumber *>(one);
    lCDNum2 = Status::findChild<QLCDNumber *>(two);
    lCDNum3 = Status::findChild<QLCDNumber *>(three);
    lCDNum4 = Status::findChild<QLCDNumber *>(four);

    timer = new QTimer(this);

    initial_1();

    connect(timer, SIGNAL(timeout()), this, SLOT(update_1()));

}

Status::~Status()
{
    delete ui;
}

void Status::summary(){
    total = ((hr*60) + (sec/60) + min);
    //INSERT INTO ORDER TABLE
    QString tt =  QString::number(total);
    QString tp =  QString::number(pay);
    int money = 0;
    QSqlQuery qry;
    QString user, d, t, order;

    qry.prepare("select user_ID from User where user_status = 1");
    qry.exec();
    qry.next();
    user = qry.value(0).toString();

    qry.prepare("select order_ID from Orderr where status = 1"); //SPOT ID IN ORDER
    qry.exec();
    qry.next();
    order = qry.value(0).toString();

    qry.exec("update Orderr set total_time = '"+tt+"' where order_ID = '"+order+"' "); //UPDATE THE TOTAL TIME
    qry.exec("update Orderr set total_payment = '"+tp+"' where order_ID = '"+order+"' "); //UPDATE THE TOTAL PAYMENT

    qry.prepare("select credit from User where user_status = 1");
    qry.exec();
    qry.next();
    money = qry.value(0).toInt();

    money = money - pay;
    tp = QString::number(money);

    qry.exec("update User set credit = '"+tp+"' where user_ID = '"+user+"' "); //MINUS THE MONEY OF USER

    d = QDate::currentDate().toString();
    t = QTime::currentTime().toString();

    qry.exec("update Orderr set date = '"+d+"' where order_ID = '"+order+"' ");
    qry.exec("update Orderr set time = '"+t+"' where order_ID = '"+order+"' ");


    hide();

    Summary a;
    a.setModal(true);
    a.setWindowTitle("Official Receipt");
    a.exec();
}

void Status::initial_1()
{
   timer->start(10);
   hr = 0;
   min = 0;
   sec = 0;
   pay = 10;
   count = 0;

   lCDNum1->display(pay);
   lCDNum2->display(hr);
   lCDNum3->display(min);
   lCDNum4->display(sec);
}

void Status::update_1()
{
    sec++;
    if(count == 5){
        pay = pay + 2;
        count = 0;
    }
    if(sec > 59) {
        sec = 0;
        min++;
        count++;
    }
    if(min > 59) {
        min = 0;
        hr++;
    }
    if(hr == 24 && min == 0 && sec == 0){
        summary();
    }

    lCDNum1->display(pay);
    lCDNum2->display(hr);
    lCDNum3->display(min);
    lCDNum4->display(sec);
}

void Status::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "End Session? ",
                    "Are you sure you want to leave your spot?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
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

        qry.exec("update Spot set spot_status = 0 where spot_ID = '"+spot+"' ");
        qry.exec("update User set user_stat = 0 where user_ID = '"+user+"' ");

        summary();
    }
}
