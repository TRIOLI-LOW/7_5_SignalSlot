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
}
void Dialog::toggleStart(bool checked){
    StopWatch* stopWatch = new StopWatch(this);

    currentTime = stopWatch->getTime(); // В любом случае присваивается лишь первый раз, не могу понять в чем дело
   // str_time = stopWatch->getTimeString();// /--/
    str_time =  QString("Время: %1 секунд").arg(currentTime) ;
    qDebug() << currentTime;
    //qDebug() << str_time <<currentTime  << stopWatch->getTime() ;
    ui->label->setText(str_time);

   if(checked == true){
     ui->start->setText("Стоп");
     stopWatch->start();
     ui->round->setEnabled(true);
   }
   else{
       ui->start->setText("Старт");
       stopWatch->stop();
       ui->round->setEnabled(false);
   }
};
void Dialog::timeLine(){
};

void Dialog::clicedRound(){
    StopWatch* stopWatch = new StopWatch(this);
        currentTime = stopWatch->getTime();
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
    stopWatch->reset();

}

Dialog::~Dialog()
{
    delete ui;
}



