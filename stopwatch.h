#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QTimer>

class StopWatch : public QObject{
    Q_OBJECT

public:
    StopWatch(QObject *parent = nullptr): QObject(parent){
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &StopWatch::updateTime);
        timer->setInterval(100);
    };
    void start(){ timer->start(100); };
    void stop (){ timer->stop(); };
    void reset (){ time = 0; };
    double getTime() const {
        return time;
    }

public: Q_SIGNALS:
         void upTime();
private slots:
         void updateTime(){
             time += 0.1;
               emit upTime();
         };
private:
    double time = 0 ;
    StopWatch* stopWatch;
    QTimer* timer;
};
#endif // STOPWATCH_H
