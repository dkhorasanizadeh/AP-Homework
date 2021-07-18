#include <QCoreApplication>
#include <iostream>
#include "server.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    server.startServer();
    return a.exec();
}
