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

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(ui->clear, &QPushButton::clicked, this, &Dialog::clicedClear);
    connect(timer, &QTimer::timeout,this,&Dialog::timeLine);
    ui->ed_time->setReadOnly(true);


}

void Dialog::toggleStart(bool checked){
    if(checked == true){
      ui->start->setText("Стоп");
      timer->start();
    }
    else{
        ui->start->setText("Старт");
        timer->stop();
    }
};
void Dialog::timeLine() {
    currentTime = ui->ed_time->text().toDouble(&ok);
    currentTime += 0.1;
    str_time= (QString::number(currentTime)) ;

    ui->ed_time->setText(QString::number(currentTime));


}

void Dialog::clicedRound(){


        currentRound = ui->ed_time->text().toDouble(&ok);
        timer->start();

        ui->ed_time->setText(QString::number(currentTime));
        ui->ed_time->setText(QString::number(0));


};

void Dialog::clicedClear(){
    ui->ed_time->setText(QString::number(0));
}

Dialog::~Dialog()
{
    delete ui;
}



