#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QTimer>
#include "stopwatch.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private Q_SLOTS:
     void updateTime();
     void toggleStart(bool checked);
     void  clicedRound();
     void clicedClear();

private:
     StopWatch* stopWatch;
     QString str_time;
     double time = 0;
     double currentRound = 0;
     double round = 0;
     int numberRound = 0;

    Ui::Dialog *ui;
};

//Пытался реализовать класс, но он передает только первое значение, в дебаге все хорошо, я не понимаю почему он не обновляет значение.
//Может я не правильно понял задание.



#endif // DIALOG_H
