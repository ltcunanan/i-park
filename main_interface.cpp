#include "main_interface.h"
#include "ui_main_interface.h"
#include "parking.h"
#include "past.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

main_interface::main_interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_interface)
{
    ui->setupUi(this);

    QSqlQuery qry;
    QString name, plate_number;
    int c = 0;
    QFont f("Arial",18);
    QFont a("Arial",25);

    QPixmap bkgnd("C:/Users/Lilian C/Documents/qtworkspace/128v3/128v03/images/prof4.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    qry.prepare("select name from User where user_status = 1");
    qry.exec();
    qry.next();
    name = qry.value(0).toString();

    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setFont(f);
    ui->label_2->setText(name);

    qry.prepare("select plate_num from User where user_status = 1");
    qry.exec();
    qry.next();
    plate_number = qry.value(0).toString();

    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->setFont(f);
    ui->label_3->setText(plate_number);

    qry.prepare("select credit from User where user_status = 1");
    qry.exec();
    qry.next();
    c = qry.value(0).toInt();

    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_4->setFont(a);
    ui->label_4->setText(QString::number(c));

}

main_interface::~main_interface()
{
    delete ui;
}

void main_interface::on_pushButton_clicked()
{
    QSqlQuery qry;
    int c = 0;

    qry.prepare("select credit from User where user_status = 1");
    qry.exec();
    qry.next();
    c = qry.value(0).toInt();

    if(c <= 0){
        QMessageBox::warning(this, "ERROR", "You do not have enough credit to make a reservation. <br> Please reload and try again.");
    }
    else{
        hide();
        parking one;
        one.setModal(true);
        one.setWindowTitle("PARKING SPOT");
        one.exec();
    }
}

void main_interface::on_pushButton_2_clicked()
{
    hide();
    Past one;
    one.setModal(true);
    one.setWindowTitle("PAST TRANSACTIONS");
    one.exec();
}

void main_interface::on_pushButton_3_clicked()
{
    QSqlQuery qry;
    QString user;

    qry.prepare("select user_ID from User where user_status = 1");
    qry.exec();
    qry.next();
    user = qry.value(0).toString();

    qry.exec("update User set user_status = 0 where user_ID = '"+user+"' ");

    this->close();
}
