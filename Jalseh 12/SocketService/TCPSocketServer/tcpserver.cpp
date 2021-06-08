#include "tcpserver.hpp"

TCPServer::TCPServer(QObject *parent)
{
}

void TCPServer::startServer()
{
    int port = 9000;
    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";
    }
}

void TCPServer::incomingConnection(qintptr socketDescriptor)
{
        qDebug() << socketDescriptor << " Connecting...";
        Thread *thread = new Thread(socketDescriptor, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
}
