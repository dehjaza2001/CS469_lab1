#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <regex>
#include <QMessageBox>
#include <string>
// #include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <QThread>

#include "./server/include/app/client_network_manager.hpp"
#include "./server/include/logic/client.hpp"
#include <string>

std::regex nickname_regex("[a-zA-Z0-9_]{1,10}");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    name = "";
    SkipTime = 1;
    barTimer = new BarTimer(20, ui->TimeBar);
    isDead = false;
    answeredQuestion = 0;
}

MainWindow::~MainWindow()
{
    //    if(socket->isOpen())
    //        socket->close();
    delete ui;
}

void MainWindow::startNewRound()
{
    isDead = false;
    answeredQuestion = 0;
    SkipTime = 1;
    setDisabledButton(false);
}

void MainWindow::waitForQuestion()
{
    ui->question_label->setText(QString("Question: %1").arg(answeredQuestion + 1));
    ui->name_label->setText(QString("Player name : %1").arg(name));
    ui->question_board->clear();
    ui->question_board->append(QString("Please wait for next player to answer"));
    setDisabledButton(true);
}

void MainWindow::displayStatus(const QString &str)
{
    // ui->status_board->clear();
    ui->status_board->setHtml(str);
}

void MainWindow::displayQuestion(const QString &str)
{
    setDisabledButton(false);
    // ui->question_board->clear();
    ui->question_board->setHtml(str);
}

void MainWindow::displayMessage(const QString &str)
{
    QMessageBox::information(this, "Client", str);
}

void MainWindow::on_StartButton_clicked()
{
    //    socket->connectToHost(QHostAddress::LocalHost,8080);
    //    if(socket->waitForConnected()){
    //        ui->statusbar->showMessage("Connected to Server");
    //        ui->stackedWidget->setCurrentIndex(1);
    //    }
    //    else{
    //        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
    //        exit(EXIT_FAILURE);
    //    }

    ClientNetworkManager &client_net = ClientNetworkManager::getInstance();
    client_net.connectToServer();

    ui->statusbar->showMessage("Connected to Server");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::sendMessage(const QString &str, const QString &fileType)
{
    //    if(socket)
    //    {
    //        if(socket->isOpen())
    //        {
    ////            QString str = ui->lineEdit->text();
    //            //displayMessage("Your name:: " + str);

    //            QDataStream socketStream(socket);
    //            socketStream.setVersion(QDataStream::Qt_5_12);

    //            QByteArray header;
    //            header.prepend(QString("fileType:%1,fileName:null,fileSize:%2;").arg(fileType).arg(str.size()).toUtf8());
    //            header.resize(128);

    //            QByteArray byteArray = str.toUtf8();
    //            byteArray.prepend(header);

    //            socketStream << byteArray;
    //            //
    //            while (socket->bytesToWrite() > 0)
    //            {
    //                QCoreApplication::processEvents();
    //                QThread::msleep(15);
    //            }

    //           // ui->lineEdit->clear();
    //        }
    //        else
    //            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    //    }
    //    else
    //        QMessageBox::critical(this,"QTCPClient","Not connected");
}

bool is_valid_nickname(const std::string &nickname)
{
    return std::regex_match(nickname, nickname_regex);
}

void MainWindow::on_GoToGameButton_clicked()
{
//    //    ui->GoToGameButton->setDisabled(true);
//    //    std::string playername = ui->NameInput->text().toStdString();
//    //    if(!is_valid_nickname(playername)){
//    //        QMessageBox::warning(this,"Invalid","Playername is incorrect");
//    //        ui->GoToGameButton->setDisabled(false);
//    //    } else {
//    //        sendMessage(QString::fromStdString(playername),QString("name"));
//    //    }

////    ui->GoToGameButton->setDisabled(true);
//    std::string playerName;
//    Client *client;

//    std::cout << "bucu";

//    ui->statusbar->showMessage("bucu to");
////    while (true)
////    {
////        std::cin >> playerName;

////        client = new (Client);
////        client->registerPlayer(playerName);

////        std::string message;
////        // check whether our name is valid
////        Information info = client->receiveResponse();
////        if (!info.res)
////        {
////            on_GoToGameButton_clicked()
////        }

//    ui->stackedWidget->setCurrentIndex(2);


//    // Wait for game start
//    Information info = client->receiveResponse();
//    client->order = info.order;
//    client->totalPlayer = info.currentSurviving;

////    while (true)
////    {
////    }
//    ui->stackedWidget->setCurrentIndex(2);
////

        std::string playerName;
        Client *client;

    this->name = ui->NameInput->text();
            client = new (Client);
            client->registerPlayer(name.toStdString());

            std::string message;
            // check whether our name is valid
            Information info = client->receiveResponse();
            if (!info.res)
            {
                on_GoToGameButton_clicked();
            }
            info = client->receiveResponse();
    ui->stackedWidget->setCurrentIndex(2);
    ui->PlayerOrder->setText(QString::fromStdString(std::to_string(info.order + 1)));
    ui->label_4->setText(QString::fromStdString(std::to_string(info.currentSurviving)));

//    info = client->receiveResponse();
//    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::setDisabledButton(bool state)
{
    ui->A_Button->setDisabled(state);
    ui->B_Button->setDisabled(state);
    ui->C_Button->setDisabled(state);
    ui->D_Button->setDisabled(state);
    ui->Skip_Button->setDisabled(state);
}

void MainWindow::on_A_Button_clicked()
{
    QString str = QString("A");
    sendMessage(str, QString("answer"));
    setDisabledButton(true);
}

void MainWindow::on_B_Button_clicked()
{
    QString str = QString("B");
    sendMessage(str, QString("answer"));
    setDisabledButton(true);
}

void MainWindow::on_C_Button_clicked()
{
    QString str = QString("C");
    sendMessage(str, QString("answer"));
    setDisabledButton(true);
}

void MainWindow::on_D_Button_clicked()
{
    QString str = QString("D");
    sendMessage(str, QString("answer"));
    setDisabledButton(true);
}

void MainWindow::on_Skip_Button_clicked()
{

    if (SkipTime == 1)
    {
        QString str = QString("SKIP");
        sendMessage(str, QString("answer"));
        SkipTime--;
        setDisabledButton(true);
    }
    else
    {
        QMessageBox::information(this, "Invalid", "You dont have any skip left");
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    startNewRound();
}

void MainWindow::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_ExitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_4_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    startNewRound();
}
