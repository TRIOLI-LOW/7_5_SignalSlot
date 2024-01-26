#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    stopWatch = new StopWatch(this);

    connect(ui->start, &QPushButton::clicked, this, &Dialog::toggleStart);
    ui->start->setCheckable(true);
    connect(ui->round, &QPushButton::clicked, this, &Dialog::clicedRound);

    connect(stopWatch, &StopWatch::upTime, this, &Dialog::updateTime);

    connect(ui->clear, &QPushButton::clicked, this, &Dialog::clicedClear);
    ui->ed_time->setReadOnly(true);
    ui->round->setEnabled(false);
}

void Dialog::updateTime(){
    time = stopWatch->getTime();
    str_time =  QString("Время: %1 секунд").arg(time) ;
    ui->label->setText(str_time);
};
void Dialog::toggleStart(bool checked){

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

void Dialog::clicedRound(){
        time = stopWatch->getTime();
        round = time - currentRound;
        currentRound += round;

        numberRound++;
        ui->ed_time->setText(QString("Круг № %1 ,Время: %2 сек").arg(numberRound).arg(round));
};

void Dialog::clicedClear(){
    ui->ed_time->setText("");
    ui->label->setText(QString("Время: "));
    numberRound = 0;
    time = 0;
    stopWatch->reset();
}

Dialog::~Dialog()
{
    delete ui;
}



