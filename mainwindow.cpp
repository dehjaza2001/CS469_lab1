#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <regex>
#include<QMessageBox>
#include<string>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include<QThread>

std::regex nickname_regex("[a-zA-Z0-9_]{1,10}");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    name = "";
    SkipTime = 1;
    barTimer = new BarTimer(20,ui->TimeBar);
    isDead = false;
    answeredQuestion = 0;
    socket = new QTcpSocket(this);
    //connect(this,&MainWindow::newRegisterName,this,&MainWindow::sendRegisterName);
    connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
    connect(this, &MainWindow::newQuestion, this, &MainWindow::displayQuestion);
    //connect(this,&MainWindow::newQuestion,this,&MainWindow::startTimeOut);
    connect(this, &MainWindow::newStatus, this, &MainWindow::displayStatus);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &MainWindow::displayError);
}

MainWindow::~MainWindow()
{
    if(socket->isOpen())
        socket->close();
    delete ui;
}

void MainWindow::startNewRound(){
    isDead = false;
    answeredQuestion = 0;
    SkipTime = 1;
    setDisabledButton(false);
}

void MainWindow::readSocket()
{
    QByteArray buffer;

    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_15);

    socketStream.startTransaction();
    socketStream >> buffer;

    if (!socketStream.commitTransaction())
    {
        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
        qDebug() << message;
        emit newMessage(message);
        return;
    }
    //qDebug() << buffer;
    QString header = buffer.mid(0,128);
    //qDebug() << header;
    QString fileType = header.split(",")[0].split(":")[1];

    buffer = buffer.mid(128);
    QString message = QString::fromStdString(buffer.toStdString());

    //qDebug() << message << " " << fileType;
    switch(ui->stackedWidget->currentIndex()) {
        case 1:
            if(fileType == "message") {
                QString cons = message.split(";")[0];
                if(cons == "OK"){
                    QString order = message.split(";")[1];
                    ui->stackedWidget->setCurrentIndex(2);
                    this->name = ui->NameInput->text();
                    ui->PlayerOrder->setText(order);
                    qDebug() << message << " " << fileType;
                } else {
                    QMessageBox::warning(this,"Invalid", "Name already taken, please try again");
                    qDebug() << "client receive " <<  message << fileType;
                    ui->GoToGameButton->setDisabled(false);
                }
            }
            break;
        case 2:
            if(fileType == "start") {
                ui->stackedWidget->setCurrentIndex(3);
                waitForQuestion();
                qDebug() << message << " " << fileType;
                //emit newStatus(message);
            }
            break;
        case 3:
            if(fileType == "question" && !isDead){
                qDebug() << message << " " << fileType;
                emit newQuestion(message);
                barTimer->start();
                connect(barTimer,&BarTimer::timeOut,this,&MainWindow::sendMessage);
            } else if (fileType == "status" && !isDead){
                qDebug() << message << " " << fileType;
                emit newStatus(message);
            } else if(fileType == "result"){
                barTimer->stop();
                if(message == "CORRECT"){
                    qDebug() << message << " " << fileType;
                    answeredQuestion++;
                    waitForQuestion();
                } else {
                    qDebug() << message << " " << fileType;
                    isDead = true;
                    ui->stackedWidget->setCurrentIndex(4);
                }
            } else {
                 qDebug() << message << " " << fileType;
                 ui->stackedWidget->setCurrentIndex(5);
                 ui->winnerboard->setHtml(QString("Congratuation you are the winner : %1").arg(message));
            }
            break;
        default:
            break;
    }
    //ui->pushButton->setEnabled(true);
}

void MainWindow::waitForQuestion(){
    ui->question_label->setText(QString("Question: %1").arg(answeredQuestion+1));
    ui->name_label->setText(QString("Player name : %1").arg(name));
    ui->question_board->clear();
    ui->question_board->append(QString("Please wait for next player to answer"));
    setDisabledButton(true);
}
void MainWindow::displayStatus(const QString &str){
    //ui->status_board->clear();
    ui->status_board->setHtml(str);
}

void MainWindow::displayQuestion(const QString &str){
    setDisabledButton(false);
    //ui->question_board->clear();
    ui->question_board->setHtml(str);
}

void MainWindow::displayMessage(const QString& str)
{
    QMessageBox::information(this,"Client",str);
}



void MainWindow::discardSocket()
{
    socket->deleteLater();
    socket=nullptr;
    ui->statusbar->showMessage("Disconnected!");
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        break;
    }
}

void MainWindow::on_StartButton_clicked()
{
    socket->connectToHost(QHostAddress::LocalHost,8080);
    if(socket->waitForConnected()){
        ui->statusbar->showMessage("Connected to Server");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }
}


void MainWindow::sendMessage(const QString& str, const QString& fileType)
{
    if(socket)
    {
        if(socket->isOpen())
        {
//            QString str = ui->lineEdit->text();
            //displayMessage("Your name:: " + str);

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray header;
            header.prepend(QString("fileType:%1,fileName:null,fileSize:%2;").arg(fileType).arg(str.size()).toUtf8());
            header.resize(128);

            QByteArray byteArray = str.toUtf8();
            byteArray.prepend(header);

            socketStream << byteArray;
            //
            while (socket->bytesToWrite() > 0)
            {
                QCoreApplication::processEvents();
                QThread::msleep(15);
            }

           // ui->lineEdit->clear();
        }
        else
            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
    }
    else
        QMessageBox::critical(this,"QTCPClient","Not connected");
}

bool is_valid_nickname(const std::string& nickname) {
    return std::regex_match(nickname, nickname_regex);
}

void MainWindow::on_GoToGameButton_clicked()
{
    ui->GoToGameButton->setDisabled(true);
    std::string playername = ui->NameInput->text().toStdString();
    if(!is_valid_nickname(playername)){
        QMessageBox::warning(this,"Invalid","Playername is incorrect");
        ui->GoToGameButton->setDisabled(false);
    } else {
        sendMessage(QString::fromStdString(playername),QString("name"));
    }
}


void MainWindow::setDisabledButton(bool state){
    ui->A_Button->setDisabled(state);
    ui->B_Button->setDisabled(state);
    ui->C_Button->setDisabled(state);
    ui->D_Button->setDisabled(state);
    ui->Skip_Button->setDisabled(state);
}

void MainWindow::on_A_Button_clicked()
{
     QString str = QString("A");
     sendMessage(str,QString("answer"));
     setDisabledButton(true);
}


void MainWindow::on_B_Button_clicked()
{
    QString str = QString("B");
     sendMessage(str,QString("answer"));
    setDisabledButton(true);

}


void MainWindow::on_C_Button_clicked()
{
    QString str = QString("C");
    sendMessage(str,QString("answer"));
    setDisabledButton(true);

}


void MainWindow::on_D_Button_clicked()
{
    QString str = QString("D");
    sendMessage(str,QString("answer"));
    setDisabledButton(true);
}


void MainWindow::on_Skip_Button_clicked()
{

    if(SkipTime == 1){
        QString str = QString("SKIP");
        sendMessage(str,QString("answer"));
        SkipTime--;
        setDisabledButton(true);
    } else {
        QMessageBox::information(this,"Invalid","You dont have any skip left");
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

