#include "summary.h"
#include "ui_summary.h"
#include "main_interface.h"

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

Summary::Summary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);

    QSqlQuery qry;
    QString name1, credit, p, user, spot1, d, t, pay, time, order;
    QFont f("Arial",11, QFont::Bold);

    QPixmap bkgnd("C:/Users/Lilian C/Documents/qtworkspace/128v3/128v03/images/rp.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    qry.prepare("select name from User where user_status = 1"); //NAME OF USER
    qry.exec();
    qry.next();
    name1 = qry.value(0).toString();

    qry.prepare("select credit from User where user_status = 1"); //CURRENT BALANCE OF USER
    qry.exec();
    qry.next();
    credit = qry.value(0).toString();

    qry.prepare("select plate_num from User where user_status = 1"); //PLATE NUMBER OF USER
    qry.exec();
    qry.next();
    p = qry.value(0).toString();

    qry.prepare("select user_ID from User where user_status = 1"); //USER ID OF USER
    qry.exec();
    qry.next();
    user = qry.value(0).toString();

    qry.prepare("select order_ID from Orderr where status = 1"); //SPOT ID IN ORDER
    qry.exec();
    qry.next();
    order = qry.value(0).toString();

    qry.prepare("select spot_ID from Orderr where order_ID = '"+order+"'"); //SPOT ID IN ORDER
    qry.exec();
    qry.next();
    spot1 = qry.value(0).toString();

    qry.prepare("select date from Orderr where order_ID = '"+order+"'"); //DATE IN ORDER
    qry.exec();
    qry.next();
    d = qry.value(0).toString();

    qry.prepare("select time from Orderr where order_ID = '"+order+"'"); //TIME IN ORDER
    qry.exec();
    qry.next();
    t = qry.value(0).toString();

    qry.prepare("select total_payment from Orderr where order_ID = '"+order+"'"); //TOTAL PAYMENT IN ORDER
    qry.exec();
    qry.next();
    pay = qry.value(0).toString();

    qry.prepare("select total_time from Orderr where order_ID = '"+order+"'"); //TOTAL TIME IN ORDER
    qry.exec();
    qry.next();
    time = qry.value(0).toString();


    ui->name->setFont(f);
    ui->name->setText(name1);

    ui->balance->setFont(f);
    ui->balance->setText(credit);

    ui->pnum->setFont(f);
    ui->pnum->setText(p);

    ui->spot->setFont(f);
    ui->spot->setText(spot1);

    ui->date->setFont(f);
    ui->date->setText(d);

    ui->time->setFont(f);
    ui->time->setText(t);

    ui->tp->setFont(f);
    ui->tp->setText(pay);

    ui->tt->setFont(f);
    ui->tt->setText(time);


}

Summary::~Summary()
{
    delete ui;
}

void Summary::on_pushButton_clicked()
{
    QSqlQuery qry;
    QString user;

    qry.prepare("select user_ID from User where user_status = 1"); //NAME OF USER
    qry.exec();
    qry.next();
    user = qry.value(0).toString();
    //STATUS = 0 past transaction
    //STATUS = 1 current transaction

    qry.exec("update Orderr set status = 0 where status = 1");

    hide();
    main_interface a;
    a.setModal(true);
    a.setWindowTitle("Profile");
    a.exec();

}
