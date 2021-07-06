#include <QApplication>

#include "tcpsocket.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  TCPSocket w;
  w.show();
  w.connectToServer();
  return a.exec();
}
