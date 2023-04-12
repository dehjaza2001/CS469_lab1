#include "mainwindow.h"
#include <QApplication>

#include "./server/include/app/client_network_manager.hpp"
#include "./server/include/logic/client.hpp"
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    a.exec();

    //    ClientNetworkManager &client_net = ClientNetworkManager::getInstance();
    //    client_net.connectToServer();

    //    std::string playerName;
    //    Client *client;
    //    while (true) {
    //        std::cin >> playerName;

    //        client = new (Client);
    //        client->registerPlayer(playerName);

    //        std::string message;
    //        // check whether our name is valid
    //        Information info = client->receiveResponse();
    //        if (info.res) {
    //            break;
    //        }

    //        std::cout << "Invalid name, please try again!\n";
    //    }

    //    // Wait for game start
    //    Information info = client->receiveResponse();
    //    client->order = info.order;
    //    client->totalPlayer = info.currentSurviving;

    //    while (true) {
    //    }

    return a.exec();
}
