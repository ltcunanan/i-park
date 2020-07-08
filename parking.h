#ifndef PARKING_H
#define PARKING_H

#include <QDialog>

namespace Ui {
class parking;
}

class parking : public QDialog
{
    Q_OBJECT

public:
    //Login conn;
    explicit parking(QWidget *parent = 0);
    ~parking();

private slots:
    void ButtonPressed(QString);

    void on_ParkSpace100_clicked();

    void on_ParkSpace101_clicked();

    void on_ParkSpace102_clicked();

    void on_ParkSpace103_clicked();

    void on_ParkSpace104_clicked();

    void on_ParkSpace105_clicked();

    void on_ParkSpace106_clicked();

    void on_ParkSpace107_clicked();

    void on_ParkSpace108_clicked();

    void on_ParkSpace109_clicked();

    void on_ParkSpace110_clicked();

    void on_ParkSpace111_clicked();

    void on_ParkSpace112_clicked();

    void on_ParkSpace113_clicked();

    void on_ParkSpace114_clicked();

    void on_ParkSpace115_clicked();

    void on_ParkSpace116_clicked();

    void on_ParkSpace117_clicked();

    void on_ParkSpace118_clicked();

    void on_ParkSpace119_clicked();

    void on_ParkSpace120_clicked();

    void on_ParkSpace121_clicked();

    void on_ParkSpace122_clicked();

    void on_ParkSpace123_clicked();

    void on_ParkSpace124_clicked();


private:
    Ui::parking *ui;
};

#endif // PARKING_H
