#include "server.hpp"

void Server::incomingConnection(qintptr socketDescriptor)
{

    qDebug() << socketDescriptor << " Connecting...";
    Worker *worker=new Worker(socketDescriptor);
    QThread *workerThread=new QThread;
    workerThreads.append(workerThread);
    worker->moveToThread(workerThread);
    connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this,SIGNAL(write(QByteArray)),worker,SLOT(writeToSocket(QByteArray)));
    connect(worker,SIGNAL(readFromSocket(int,qintptr)),this,SLOT(read(int,qintptr)));
    connect(this, &Server::run, worker, &Worker::start);
    workerThread->start();
    emit run();
}

Server::Server(QObject *parent)
{

}

Server::~Server()
{
    for(auto &workerThread:workerThreads){
        workerThread->quit();
        workerThread->wait();
        delete workerThread;
    }
}

void Server::startServer()
{  int port = 9000;
    if (!this->listen(QHostAddress::Any, port)) {
      qDebug() << "Could not start server";
    } else {
      qDebug() << "Listening to port " << port << "...";
    }
}

void Server::read(int data, qintptr descriptor)
{
    qDebug() << descriptor << " Data in: " << data;
    QString i=QString::number(descriptor)+" Said "+QString::number(data);
    emit write(i.toUtf8());
}
