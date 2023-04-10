#ifndef BARTIMER_H
#define BARTIMER_H
#include<QTimer>
#include<QProgressBar>
#include <QObject>
class BarTimer : public QObject
{
    Q_OBJECT
public:
    //BarTimer();
    explicit BarTimer(int time, QProgressBar* bar);
    ~BarTimer();
    void start();
    void stop();
signals:
    void timeOut(QString msg, QString fileType);
private :
    QTimer* timer ;
    QProgressBar* bar;
    int time;
    void update();

};

#endif // BARTIMER_H
