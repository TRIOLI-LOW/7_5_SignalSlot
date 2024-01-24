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
     void clicedClear();
    void timeLine();
private:

     bool ok = true;
     QString str_time;
     double currentTime = 0;
     double currentRound = 0;
     int numberRound = 0;

    Ui::Dialog *ui;
};

//Пытался реализовать класс, но он передает только первое значение, в дебаге все хорошо, я не понимаю почему он не обновляет значение.
//Может я не правильно понял задание.

class StopWatch : public Dialog{
    Q_OBJECT
public:
    StopWatch(Dialog *parent = nullptr): Dialog(parent){
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &StopWatch::upTime);
        timer->setInterval(100);
    };
    void start(){ timer->start(100); };
    void stop (){ timer->stop(); };
    void reset (){ time = 0; };

    QString getTimeString() const{
        //qDebug() <<  timeString << time ;
        return timeString;
    }
    double getTime() const {
        return time;
    }
      double time = 0 ;
public slots:
    void upTime(){
        time += 0.1;

        timeString = QString("Время: %1 секунд").arg(time) ;
       qDebug() <<  timeString << time ;

}
private:

    QString timeString;
    QTimer* timer;
};

#endif // DIALOG_H
