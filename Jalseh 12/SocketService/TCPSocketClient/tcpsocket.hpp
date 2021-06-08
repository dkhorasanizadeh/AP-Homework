#ifndef TCPSOCKET_HPP
#define TCPSOCKET_HPP

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TCPSocket; }
QT_END_NAMESPACE

class TCPSocket : public QMainWindow
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    Ui::TCPSocket *ui;
    QMessageBox *message;
public:
    TCPSocket(QWidget *parent = nullptr);
    ~TCPSocket();
    void connectToServer(void);
public slots:
    void send(void);
};
#endif // TCPSOCKET_HPP
