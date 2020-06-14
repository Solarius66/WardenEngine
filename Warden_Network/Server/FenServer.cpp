/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenServer
*/

#include "FenServer.h"

Fenserver::Fenserver(int port)
{
    serverState = new QLabel;
    exitButton = new QPushButton(tr("Exit"));
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(serverState);
    layout->addWidget(exitButton);
    setLayout(layout);

    setWindowTitle(tr("WardenServer - server"));

    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::LocalHost, port)) {
        serverState->setText(tr("Echec start server:<br />") + server->errorString());
    } else {
        serverState->setText(tr("Server start on <strong>") + QString::number(server->serverPort()) + tr("</strong>.<br />Clients can now connect."));
        connect(server, SIGNAL(newConnection()), this, SLOT(this->myNewConnection()));
    }
    sizeMessage = 0;
}

Fenserver::~Fenserver()
{
}

void Fenserver::myNewConnection()
{
    QTcpSocket *newClient = server->nextPendingConnection();
    clients << newClient;

    connect(newClient, SIGNAL(readyRead()), this, SLOT(dataReceve()));
    connect(newClient, SIGNAL(disconnected()), this, SLOT(clientLogout()));
    qDebug() << "COnnection!";
}

QString Fenserver::dataReceve()
{
    QString message;
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == 0) {
        return nullptr;
    }
    QDataStream in(socket);
    if (sizeMessage == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return nullptr;
        in >> sizeMessage;
    }
    if (socket->bytesAvailable() < sizeMessage)
        return nullptr;
    in >> message;
    sizeMessage = 0;
    qDebug() << message;
    return message;

}

void Fenserver::clientLogout()
{
    sendAll(tr("<em>A Client logout</em>"));

    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0)
        return;
    clients.removeOne(socket);
    socket->deleteLater();
}

void Fenserver::sendAll(const QString &message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->write(paquet);
    }

}
