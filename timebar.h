#ifndef TIMEBAR_H
#define TIMEBAR_H
#include<QTimer>
#include<QProgressBar>

class TimeBar
{
public:
    TimeBar(int time, QProgressBar& timeBar);
    ~TimeBar();
    start();
    end();
private :
    QTimer* timer;
    int time;

};

#endif // TIMEBAR_H
