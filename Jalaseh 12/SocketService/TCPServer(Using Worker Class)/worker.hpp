#ifndef WORKER_HPP
#define WORKER_HPP

#include <QObject>
#include <QTcpSocket>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(qintptr ID, QObject *parent = nullptr);
    QTcpSocket *socket;
    qintptr socketDescriptor;
signals:
    void error(QTcpSocket::SocketError socketerror);
    void readFromSocket(int,qintptr);
public slots:
    void start(void);
    void writeToSocket(QByteArray data);
    void readyRead(void);
    void disconnected(void);
};

#endif // WORKER_HPP
