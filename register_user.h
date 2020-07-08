#ifndef REGISTER_USER_H
#define REGISTER_USER_H

#include <QDialog>
#include "login.h"

namespace Ui {
class register_user;
}

class register_user : public QDialog
{
    Q_OBJECT

public:
    Login conn;
    explicit register_user(QWidget *parent = 0);
    ~register_user();

private slots:
    void on_pushButton_clicked();

private:
    Ui::register_user *ui;
};

#endif // REGISTER_USER_H
