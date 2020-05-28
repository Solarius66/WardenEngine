#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QJsonDocument>

#include "warden_lib.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IScene *scene = new AScene("Test");
    QSharedPointer<AGameObject> obj= QSharedPointer<AGameObject>(new AGameObject ("obj", PLAYER, FOREGROUND));
    obj->addComponent<MeshRenderer>("MeshRenderer", "./texture", "./texture", "./texture");
    scene->addObject(obj);
    qDebug() << scene->getFromName("obj")->getComponent<MeshRenderer>("MeshRenderer").getText() << '\n';
    w.show();

    QJsonObject file;

    qDebug() << "SAVE!" << '\n';
    QFile saveFile(QStringLiteral("save.json"));
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }
    scene->write(file);
    QJsonDocument saveDoc(file);
    saveFile.write(saveDoc.toJson());

    return a.exec();
}
