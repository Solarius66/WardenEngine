/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenClient
*/

#ifndef FENCLIENT_H_
#define FENCLIENT_H_

#include <QtWidgets>
#include <QtNetwork>

class FenClient : public QWidget
{
    Q_OBJECT
    public:
        FenClient(int port);
        ~FenClient();

        void onConnexion(const QString &hostName, quint16 port);
        void sendMessage(const QString &message);
        QString dataReceve();

    private:
        QTcpSocket *socket;
        quint16 sizeMessage;
};

#endif /* !FENCLIENT_H_ */