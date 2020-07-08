#ifndef PAST_H
#define PAST_H

#include <QDialog>

namespace Ui {
class Past;
}

class Past : public QDialog
{
    Q_OBJECT

public:
    explicit Past(QWidget *parent = 0);
    ~Past();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Past *ui;
};

#endif // PAST_H
