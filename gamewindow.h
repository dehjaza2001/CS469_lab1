#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include<string>
//#include <windows.h>
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

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    explicit GameWindow(QWidget *parent = nullptr, std::string name = "");
    ~GameWindow();

signals:
    void newMessage(QString);

private slots:
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayMessage(const QString& str);
    void sendMessage(const QString& str);
    void setDisabledButton(bool state);

    void startTimeOut();

    void on_A_Button_clicked();

    void on_B_Button_clicked();

    void on_C_Button_clicked();

    void on_D_Button_clicked();

    void on_Skip_Button_clicked();

    void updateProgressBar();

private:
    Ui::GameWindow *ui;
    QString name;

};

#endif // GAMEWINDOW_H
