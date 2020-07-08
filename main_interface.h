#ifndef MAIN_INTERFACE_H
#define MAIN_INTERFACE_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class main_interface;
}

class main_interface : public QDialog
{
    Q_OBJECT

public:

    explicit main_interface(QWidget *parent = 0);
    ~main_interface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::main_interface *ui;
};

#endif // MAIN_INTERFACE_H
