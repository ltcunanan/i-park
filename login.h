#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <main_interface.h>
//#include "parking.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT
public:

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Login *ui;
};

#endif // LOGIN_H
