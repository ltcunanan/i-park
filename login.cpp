#include "main.cpp"
#include "login.h"
#include "main_interface.h"
#include "ui_login.h"
#include <register_user.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
#include <QPixmap>
#include <QPalette>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    QSqlDatabase mydb;
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/Lilian C/Documents/qtworkspace/128v3/128v03/images/bg2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    mydb=QSqlDatabase::addDatabase("QSQLITE");
//    mydb=QSqlDatabase::addDatabase("QMYSQL");
    mydb.setDatabaseName("C:/Users/Lilian C/Documents/qtworkspace/128v3/IParkk.db");

   if(!mydb.open())
        ui->label_login->setText("Failed to open database");
    else
        ui->label_login->setText("Connected. . .");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //username = name
    //password = empid

    QString username, password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();


    QSqlQuery qry;
    qry.prepare("select * from User where name='"+username +"' and User_id='"+password+"'");

    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count==1){ //open other window
            ui->label_login->setText("username and password is correct");

            qry.prepare("update User set user_status =  1  where user_ID = '"+password+"'");
            qry.exec();
            //QMessageBox::warning(this, "UPDATE SUCCESS", "active column should have been updated");

            this->hide();
            main_interface a;
            a.setModal(true);
            a.setWindowTitle("PROFILE PAGE");
            a.exec();
        }
        else if(count>1){
            ui->label_login->setText("another user logged in");
        }
        else
            ui->label_login->setText("username and password is not correct");
    }
}

void Login::on_pushButton_2_clicked()
{
    register_user reg;
    reg.setModal(true);
    reg.setWindowTitle("REGISTER PAGE");
    reg.exec();
}

