#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include<string>
#include <windows.h>
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

private slots:
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
