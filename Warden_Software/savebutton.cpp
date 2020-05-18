#include "savebutton.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

SaveButton::SaveButton(QWidget *parent) : QPushButton(parent)
{
    setText("Save");
}

void SaveButton::clicked(std::shared_ptr<wd::IScene> scene, bool checked)
{
    QJsonObject file;

    QFile saveFile(QStringLiteral("save.json"));
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    file["Scene"] = QString::fromUtf8(scene->getName().c_str());

    QJsonArray objArray;
    foreach (std::shared_ptr<wd::AGameObject> obj, scene->getObjects()) {
        QJsonObject objJson;
        //obj.write(objJson);
        objArray.append(objJson);
    }
    file["GameObject"] = objArray;
    QJsonDocument saveDoc(objArray);
    saveFile.write(saveDoc.toJson());
}
