#include <QCoreApplication>

#include "tcpserver.hpp"
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  TCPServer Server;
  Server.startServer();
  return a.exec();
}
