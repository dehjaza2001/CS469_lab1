#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <regex>
#include<QMessageBox>
#include<string>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

std::regex nickname_regex("[a-zA-Z0-9_]{1,10}");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_StartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

bool is_valid_nickname(const std::string& nickname) {
    return std::regex_match(nickname, nickname_regex);
}

void MainWindow::on_GoToGameButton_clicked()
{
    std::string playername = ui->NameInput->text().toStdString();
    if(!is_valid_nickname(playername)){
        QMessageBox::warning(this,"Invalid","Playername is incorrect");
    } else {
        //
        hide();
        gameWindow = new GameWindow(this,playername);
        gameWindow->show();

    }

}









