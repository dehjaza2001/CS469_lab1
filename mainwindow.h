#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include<string>
#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QTimer>
#include "bartimer.h"
#include<QCoreApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 signals :
    void newMessage(QString);
    void newQuestion(QString);
    void newStatus(QString);

private slots:
    void setDisabledButton(bool state);
    void startNewRound();
    void sendMessage(const QString& str, const QString& fileType);
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString& str);
    void displayQuestion(const QString& str);
    void displayStatus(const QString& str);
    void waitForQuestion();


    void on_A_Button_clicked();

    void on_B_Button_clicked();

    void on_C_Button_clicked();

    void on_D_Button_clicked();

    void on_Skip_Button_clicked();

    void on_GoToGameButton_clicked();

    void on_StartButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ExitButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    BarTimer * barTimer;
    GameWindow* gameWindow;
    QTcpSocket* socket;
    QString name;
    bool isDead;
    int answeredQuestion;
    int SkipTime;
};
#endif // MAINWINDOW_H
