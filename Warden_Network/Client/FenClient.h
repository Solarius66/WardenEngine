/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenClient
*/

#ifndef FENCLIENT_H_
#define FENCLIENT_H_

#include <QtNetwork>
#include <QObject>

class FenClient : public QObject
{
    Q_OBJECT
    public:
        FenClient();
        ~FenClient();

        void onConnexion(const QString &hostName, quint16 port);
        void sendMessage(const QString &message);

public slots:
        QString dataRecive();

    private:
        QTcpSocket *socket;
        quint16 sizeMessage;
};

#endif /* !FENCLIENT_H_ */
