#include "worker.hpp"

Worker::Worker(qintptr ID,QObject *parent) : QObject(parent)
{
    socketDescriptor = ID;
    socket=nullptr;
}

void Worker::start()
{
    if(socket==nullptr){
    socket = new QTcpSocket();
    if (!socket->setSocketDescriptor(this->socketDescriptor)) {
      emit error(socket->error());
      return;
    }
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()),
            Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    qDebug() << socketDescriptor << " Client connected";}
}

void Worker::writeToSocket(QByteArray data)
{
    socket->write(data);
}

void Worker::readyRead()
{
    QByteArray Data = socket->readAll();
    int number = QString(Data).toInt();
    emit readFromSocket(number,socketDescriptor);
}

void Worker::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
}
