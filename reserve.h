#ifndef RESERVE_H
#define RESERVE_H

#include <QDialog>

namespace Ui {
class reserve;
}

class reserve : public QDialog
{
    Q_OBJECT

public:
    explicit reserve(QWidget *parent = 0);
    ~reserve();

private slots:
    void ButtonPressed();


private:
    Ui::reserve *ui;
};

#endif // RESERVE_H
