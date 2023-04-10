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
    // set up socket
//    socket = new QTcpSocket(this);


    //test
    name = QString::fromStdString(playername);
    ui->nametag->setText(name);
    ui->stackedWidget->setCurrentIndex(0);
    //

//    connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
//    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
//    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
//    connect(socket, &QAbstractSocket::errorOccurred, this, &MainWindow::displayError);
//    connect(this, &MainWindow::newMessage, this, &MainWindow::startTimeOut);
//    QTimer *timer = new QTimer(this);

//    // Connect the timeout signal of the timer to a slot that switches to the next page
//    connect(timer, &QTimer::timeout, [=]() {
//        ui->stackedWidget->setCurrentIndex(1);
//        timer->stop();
//    });


//    timer->setInterval(5000);

//    // Start the timer
//    timer->start();
    // connect to server
}

GameWindow::~GameWindow()
{
//    if(socket->isOpen())
//        socket->close();
    delete ui;
}

void GameWindow::startTimeOut(){
//    QTimer *bartimer = new QTimer(this);
//    connect(bartimer, &QTimer::timeout, this, &GameWindow::updateProgressBar);
//    bartimer->start(1000);
}

void GameWindow::updateProgressBar() {
        // Get the current value of the progress bar and increment it by 10
//        QProgressBar * timerBar = ui->TimeBar;
//        int currentValue = timerBar->value();
//        int newValue = currentValue - 1;

//        // If the progress bar has reached its maximum value, stop the timer
//        if (newValue <= 0) {
//            QTimer *bartimer = qobject_cast<QTimer *>(sender());
//            bartimer->stop();
//            sendMessage(QString("TimeOut"));
//            ui->stackedWidget->setCurrentIndex(2);
//        }

//        // Update the value of the progress bar
//        timerBar->setValue(newValue);
    }

void GameWindow::readSocket()
{
//    QByteArray buffer;

//    QDataStream socketStream(socket);
//    socketStream.setVersion(QDataStream::Qt_5_15);

//    socketStream.startTransaction();
//    socketStream >> buffer;

//    if (!socketStream.commitTransaction())
//    {
//        QString message = QString("%1 :: Waiting for more data to come..").arg(socket->socketDescriptor());
//        emit newMessage(message);
//        return;
//    }
//    qDebug() << buffer;
//    QString header = buffer.mid(0,128);
//    qDebug() << header;
//    QString fileType = header.split(",")[0].split(":")[1];

//    buffer = buffer.mid(128);

//    if (fileType == "message")
//    {
//        QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
//        emit newMessage(message);
//    }

//    if (fileType == "Status")
//    {
//        ui->textBrowser_2->clear();
//        ui->textBrowser_2->append(QString::fromStdString(buffer.toStdString()));
//    }

//   // ui->pushButton->setEnabled(true);
//   setDisabledButton(false);
}

void GameWindow::discardSocket()
{
//    socket->deleteLater();
//    socket=nullptr;

//    ui->statusbar->showMessage("Disconnected!");
}

void GameWindow::displayError(QAbstractSocket::SocketError socketError)
{
//    switch (socketError) {
//        case QAbstractSocket::RemoteHostClosedError:
//        break;
//        case QAbstractSocket::HostNotFoundError:
//            QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
//        break;
//        case QAbstractSocket::ConnectionRefusedError:
//            QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
//        break;
//        default:
//            QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
//        break;
//    }
}

//void MainWindow::displayMessage(const QString& str)
//{
////    ui->textBrowser_2->clear();
////    ui->textBrowser->append(str);
//}

//void MainWindow::sendMessage(const QString& str)
//{
//    if(socket)
//    {
//        if(socket->isOpen())
//        {
//            //displayMessage("Me:: " + str);

//            QDataStream socketStream(socket);
//            socketStream.setVersion(QDataStream::Qt_5_15);

//            QByteArray header;
//            header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
//            header.resize(128);

//            QByteArray byteArray = str.toUtf8();
//            byteArray.prepend(header);

//            socketStream << byteArray;

//            //ui->lineEdit->clear();
//        }
//        else
//            QMessageBox::critical(this,"QTCPClient","Socket doesn't seem to be opened");
//    }
//    else
//        QMessageBox::critical(this,"QTCPClient","Not connected");
//}

void GameWindow::setDisabledButton(bool state){
    ui->A_Button->setDisabled(state);
    ui->B_Button->setDisabled(state);
    ui->C_Button->setDisabled(state);
    ui->D_Button->setDisabled(state);
    ui->Skip_Button->setDisabled(state);
}

void GameWindow::on_A_Button_clicked()
{
     QString str = QString("A");
     //sendMessage(str);
     setDisabledButton(true);
}


void GameWindow::on_B_Button_clicked()
{
    QString str = QString("B");
    //sendMessage(str);
    setDisabledButton(true);

}


void GameWindow::on_C_Button_clicked()
{
    QString str = QString("C");
    //sendMessage(str);
    setDisabledButton(true);

}


void GameWindow::on_D_Button_clicked()
{
    QString str = QString("D");
    //sendMessage(str);
    setDisabledButton(true);
}


void GameWindow::on_Skip_Button_clicked()
{
    QString str = QString("SKIP");
    //sendMessage(str);
    setDisabledButton(true);
}

