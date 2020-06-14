/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenClient
*/

#include "FenClient.h"


FenClient::FenClient()
{
    socket = new QTcpSocket(this);
    sizeMessage = 0;
    connect(socket, SIGNAL(readyRead()), this, SLOT(dataRecive()));
}

FenClient::~FenClient()
{
}

void FenClient::onConnexion(const QString &hostName, quint16 port)
{
    socket->abort();
    socket->connectToHost(hostName, port);
    if (socket->isValid())
        qDebug() << "ok";
    else
        qDebug() << "ko";
}

void FenClient::sendMessage(const QString &message)
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

//    out << (quint16) 0;
    out << message;
//    out.device()->seek(0);
//    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(message.toStdString().c_str());
}

QString FenClient::dataRecive()
{
    QString newMessage;
    QDataStream in(socket);

    if (sizeMessage == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return nullptr;
        in >> sizeMessage;
    }
    if (socket->bytesAvailable() < sizeMessage)
        return nullptr;
    in >> newMessage;
    sizeMessage = 0;
    return newMessage;
}
