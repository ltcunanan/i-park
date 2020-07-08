#ifndef SUMMARY_H
#define SUMMARY_H

#include <QDialog>

namespace Ui {
class Summary;
}

class Summary : public QDialog
{
    Q_OBJECT

public:
    explicit Summary(QWidget *parent = 0);
    ~Summary();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Summary *ui;
};

#endif // SUMMARY_H
