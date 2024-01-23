#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->start, &QPushButton::clicked, this, &Dialog::toggleStart);
    ui->start->setCheckable(true);
    connect(ui->round, &QPushButton::clicked, this, &Dialog::clicedRound);

    connect(ui->clear, &QPushButton::clicked, this, &Dialog::clicedClear);
    ui->ed_time->setReadOnly(true);
    ui->round->setEnabled(false);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dialog::timeLine);

}
void Dialog::toggleStart(bool checked){

    // StopWatch* stopWatch = new StopWatch(this);
    //setTime (stopWatch->getTime());
    // qDebug() << currentTime << stopWatch->getTime() ;


    str_time = QString("Время: %1 секунд").arg(currentTime) ;
    ui->label->setText(str_time);

   if(checked == true){
     ui->start->setText("Стоп");
    // stopWatch->start();
     timer->start(100);
     ui->round->setEnabled(true);
   }
   else{
       ui->start->setText("Старт");
      // stopWatch->stop();
       timer->stop();
       ui->round->setEnabled(false);
   }
};
void Dialog::timeLine(){
    currentTime += 0.1;
    str_time = QString("Время: %1 секунд").arg(currentTime) ;
    ui->label->setText(str_time);

};

void Dialog::clicedRound(){
        currentRound = currentTime;
        currentTime = 0;
        numberRound++;
        ui->ed_time->setText(QString("Круг № %1 ,Время: %2 сек").arg(numberRound).arg(currentRound));
};

void Dialog::clicedClear(){
    StopWatch* stopWatch = new StopWatch(this);
    ui->ed_time->setText("");
    ui->label->setText(QString("Время: "));
    numberRound = 0;
    currentTime = 0;
    //stopWatch->reset();

}

Dialog::~Dialog()
{
    delete ui;
}



