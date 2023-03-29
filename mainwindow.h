#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartButton_clicked();

    void on_GoToGameButton_clicked();

    void on_SkipButton_clicked();

    void on_BackToMenuButton_clicked();


private:
    Ui::MainWindow *ui;
    GameWindow *GameWindow;

};
#endif // MAINWINDOW_H
