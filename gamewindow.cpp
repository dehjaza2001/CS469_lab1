#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QProgressBar>
#include <QTimer>
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::GameWindow(QWidget *parent, std::string playername) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    name = QString::fromStdString(playername);
    ui->nametag->setText(name);
    ui->stackedWidget->setCurrentIndex(0);
    //
    QTimer *timer = new QTimer(this);

    // Connect the timeout signal of the timer to a slot that switches to the next page
    connect(timer, &QTimer::timeout, [=]() {

        ui->stackedWidget->setCurrentIndex(1);
        QTimer *bartimer = new QTimer(this);
        connect(bartimer, &QTimer::timeout, this, &GameWindow::updateProgressBar);
        bartimer->start(1000);
        timer->stop();
    });


    timer->setInterval(5000);

    // Start the timer
    timer->start();
    //


}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::updateProgressBar() {
        // Get the current value of the progress bar and increment it by 10
        QProgressBar * timerBar = ui->TimeBar;
        int currentValue = timerBar->value();
        int newValue = currentValue - 1;

        // If the progress bar has reached its maximum value, stop the timer
        if (newValue <= 0) {
            QTimer *bartimer = qobject_cast<QTimer *>(sender());
            bartimer->stop();
            ui->stackedWidget->setCurrentIndex(2);
        }

        // Update the value of the progress bar
        timerBar->setValue(newValue);
    }

void GameWindow::on_A_Button_clicked()
{

}


void GameWindow::on_B_Button_clicked()
{

}


void GameWindow::on_C_Button_clicked()
{

}


void GameWindow::on_D_Button_clicked()
{

}


void GameWindow::on_Skip_Button_clicked()
{

}

