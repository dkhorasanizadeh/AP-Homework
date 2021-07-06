#include "thread.hpp"

Thread::Thread(qintptr ID, QObject *parent) : QThread(parent) {
  socketDescriptor = ID;
}

void Thread::run() {
  qDebug() << " Thread started";
  socket = new QTcpSocket();
  if (!socket->setSocketDescriptor(this->socketDescriptor)) {
    emit error(socket->error());
    return;
  }
  connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),
          Qt::DirectConnection);
  connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
  qDebug() << socketDescriptor << " Client connected";
  exec();
}

void Thread::readyRead() {
  QByteArray Data = socket->readAll();
  qDebug() << socketDescriptor << " Data in: " << Data;
  int number = QString(Data).toInt();
  Data.setNum(number * number);
  socket->write(Data + "\n");
}

void Thread::disconnected() {
  qDebug() << socketDescriptor << " Disconnected";
  socket->deleteLater();
  exit(0);
}
