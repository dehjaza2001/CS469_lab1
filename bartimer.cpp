#include "bartimer.h"

//BarTimer::BarTimer()
//{
//    time = 20;
//}

BarTimer::BarTimer(int time, QProgressBar*bar){
    this->time = time;
    this->timer = new QTimer(this);
    this->bar = bar;
}

BarTimer::~BarTimer(){
    timer = NULL;
    bar = NULL;
    delete timer;
    delete bar;
}

void BarTimer::start(){
    connect(timer, &QTimer::timeout, this, &BarTimer::update);
    timer->start(1000);
}

void BarTimer::update(){
    int curValue = bar->value();
    int nextValue = curValue - 1;

    if(nextValue <= 0){
        this->stop();
        emit timeOut(QString("TimeOut"), QString("answer"));
    }
    this->bar->setValue(nextValue);
}

void BarTimer::stop(){
    timer->stop();
    bar->setValue(time);
    disconnect(timer, &QTimer::timeout, this, &BarTimer::update);
    //this->~BarTimer();
}
