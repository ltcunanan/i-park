#ifndef PARKINGPOPUP_H
#define PARKINGPOPUP_H

#include <QDialog>

namespace Ui {
class parkingPopUp;
}

class parkingPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit parkingPopUp(QWidget *parent = 0);
    ~parkingPopUp();

private:
    Ui::parkingPopUp *ui;
};

#endif // PARKINGPOPUP_H
