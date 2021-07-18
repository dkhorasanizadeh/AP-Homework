#include "tcpsocket.hpp"

#include "ui_tcpsocket.h"

TCPSocket::TCPSocket(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TCPSocket) {
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  message = new QMessageBox();
  ui->SendButton->setDisabled(true);
  connect(ui->SendButton, SIGNAL(clicked()), this, SLOT(send()));
  connect(socket,SIGNAL(readyRead()),this,SLOT(recieve()));
}

TCPSocket::~TCPSocket() {
  socket->close();
  delete ui;
  delete socket;
}

void TCPSocket::connectToServer() {
  socket->connectToHost("127.0.0.1", 9000);
  if (socket->waitForConnected(3000)) {
    message->setText("Connected.");
    message->exec();
    ui->SendButton->setDisabled(false);
  } else {
    message->setText("Not Connected.");
    message->exec();
    this->close();
    return;
  }
}

void TCPSocket::send() {
  QByteArray Data;
  Data.setNum(ui->InputLineEdit->text().toInt());
  socket->write(Data + "\n");
}

void TCPSocket::recieve()
{
    QByteArray Data;
    qDebug() << "Reading:" << socket->bytesAvailable();
    Data = socket->readAll();
    ui->OutputLabel->setText(QString(Data));
}
