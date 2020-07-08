#include "login.h"
#include "register_user.h"
#include "ui_register_user.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

register_user::register_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_user)
{
    ui->setupUi(this);
}

register_user::~register_user()
{
    delete ui;
}

void register_user::on_pushButton_clicked()
{
    QSqlQuery qry;
    QString username, plate_number, name;
    username=ui->lineEdit_Username->text(); //?????????????
    plate_number=ui->lineEdit_Plate_Number->text();
    name=ui->lineEdit_Name->text();


    /*qry.prepare("insert into User(User_id, plate_number, name, spot_number, credit, order_id, active, user_stat) values(NULL,'"+plate_number+"','"+name+"',NULL, NULL, NULL, 1, 1)");
    QUERY IS NOT UPDATED
    if(qry.exec())
    {
         QMessageBox::critical(this, tr("SAVE"), tr("SAVED"));
    }


    else
    {
        // QMessageBox::critical(this, tr("error::"), qry.lastError.text());
         QMessageBox::critical(this, tr("error::"),tr ("error"));
    }*/

}


//coffeeprince1stfloor
//coffeeprince032
