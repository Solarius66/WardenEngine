#include "savebutton.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QtDebug>

#include "warden_lib.h"

SaveButton::SaveButton(QWidget *parent) : QPushButton(parent)
{
    setText("Save");
}

//void SaveButton::handleButton(QSharedPointer<IScene> scene)
//{
//    QJsonObject file;

//    qDebug() << "SAVE!" << '\n';
//    QFile saveFile(QStringLiteral("save.json"));
//    if (!saveFile.open(QIODevice::WriteOnly)) {
//        qWarning("Couldn't open save file.");
//    }
//    scene->write(file);
//    QJsonDocument saveDoc(file);
//    saveFile.write(saveDoc.toJson());
//}
