/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GameObject Abstract class implementation
*/

#include <QString>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

#include "include/engine/data/AGameObject.hpp"
#include "include/engine/data/Transform.hpp"

AGameObject::AGameObject(const QString &name, int id, int layer) : _name(name), _id(id), _layer(layer)
{
    addComponent<Transform>("Transform");
}

AGameObject::AGameObject(AGameObject &obj) : _name(obj.getName()), _id(obj.getID()), _layer(obj.getLayer())
{
}

void AGameObject::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();
    if (json.contains("id") && json["id"].isString())
        _name = json["id"].toInt();
    if (json.contains("layer") && json["layer"].isString())
        _name = json["layer"].toInt();
    if (json.contains("object") && json["object"].isArray()) {
        QJsonArray objArray = json["object"].toArray();
        _component.clear();
        for (int compoIndex = 0; compoIndex < objArray.size(); ++compoIndex) {
            QJsonObject compoObject = objArray[compoIndex].toObject();
            QSharedPointer<AComponent> compo;
            compo->read(compoObject);
//            addComponent<AComponent>(compo->getName(), compo);
        }
    }
}

void AGameObject::write(QJsonObject &json) const
{
    json["name"] = _name;
    json["id"] = _id;
    json["layer"] = _layer;
    QJsonArray objectArray;
    for (auto const& x : _component) {
        QJsonObject gameObject;
        x->write(gameObject);
        objectArray.append(gameObject);
    }
    json["component"] = objectArray;
}

void AGameObject::debug()
{
    qDebug() << getName() << " :" << '\n';
    for (auto const& x : _component)
        qDebug() << x->getName() << '\n';
}

void AGameObject::update(event event)
{
    for (auto const& x : _component)
        x->update(event);
}
