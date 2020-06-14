/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** FenServer
*/

#ifndef FENSERVER_H_
#define FENSERVER_H_


#include <QtWidgets>
#include <QtNetwork>



class FenServeur : public QWidget
{
    Q_OBJECT
    public:
        FenServeur(int port);
        ~FenServeur();
        void sendAll(const QString &message);
        QString dataReceve();

    private slots:
        void myNewConnection();
        void clientLogout();

    private:
        QLabel *serverState;
        QPushButton *exitButton;
        QTcpServer *server;
        QList<QTcpSocket *> clients;
        quint16 sizeMessage;
};

#endif /* !FENSERVER_H_ */
