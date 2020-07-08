#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include "login.h"

class QTimer;
class QLCDNumber;

namespace Ui {
class Reservation;
}

class Reservation : public QDialog
{
    Q_OBJECT

public:
     Login conn;
    explicit Reservation(QWidget *parent = 0);
    ~Reservation();
     int scount, mcount;
     QLCDNumber *lCDNumber2;
     QLCDNumber *lCDNumber3;
     QTimer *updatetimer;

private slots:
    void update();
    void initial();
    void status();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
