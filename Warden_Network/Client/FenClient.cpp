/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenClient
*/

#include "FenClient.hpp"


FenClient::FenClient()
{
    socket = new QTcpServer(this);
    sizeMessage = 0;
}

FenClient::~FenClient()
{
}

void FenClient::onConnexion(const QString &hostName, quint16 port)
{
    socket->abort();
    socket->connectToHost(hostName, port);
}

void FenClient::sendMessage(const QString &message);
{
    QByteArray paquet;
    QDataStream out(&paquet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (paquet.size() - sizeof(quint16));

    socket->write(paquet);
}

QString FenClient::dataReceve();
{
    QString newMessage;
    QDataStream in(socket);

    if (sizeMessage == 0) {
        if (socket->bytesAvailable() < (int)sizeof(quint16))
             return;
        in >> sizeMessage;
    }
    if (socket->bytesAvailable() < sizeMessage)
        return;
    in >> newMessage;
    sizeMessage = 0;
    return newMessage;
}