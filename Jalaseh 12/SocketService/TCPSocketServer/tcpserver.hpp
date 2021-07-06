#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QObject>
#include <QTcpServer>

#include "thread.hpp"

class TCPServer : public QTcpServer {
  Q_OBJECT
 private:
  void incomingConnection(qintptr socketDescriptor);

 public:
  explicit TCPServer(QObject *parent = 0);
  void startServer(void);
};

#endif  // TCPSERVER_HPP
