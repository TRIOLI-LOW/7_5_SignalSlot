#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

Q_SIGNALS:
    void signalToggleStart(bool checked);

private Q_SLOTS:

    void toggleStart(bool checked);
     void  clicedRound();
     void timeLine();
     void clicedClear();

private:
     bool ok = true;
     QString str_time;
     double currentTime;
     double currentRound;
    QTimer* timer;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
