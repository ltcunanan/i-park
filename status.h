#ifndef STATUS_H
#define STATUS_H

#include <QDialog>

class QTimer;
class QLCDNumber;

namespace Ui {
class Status;
}

class Status : public QDialog
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = 0);
    ~Status();
    int sec, min, hr;
    int total , pay, count;
    QLCDNumber *lCDNum1;
    QLCDNumber *lCDNum2;
    QLCDNumber *lCDNum3;
    QLCDNumber *lCDNum4;
    class QTimer *timer;

private slots:
    void initial_1();
    void update_1();
    void summary();

    void on_pushButton_clicked();

private:
    Ui::Status *ui;
};

#endif // STATUS_H
