/*
** EPITECH PROJECT, 2019
** AScene.cpp
** File description:
** AScene Class Implementation
*/

#include <QDebug>
#include <QJsonArray>

#include "include/engine/data/AScene.hpp"
#include "include/engine/data/SceneState.hpp"
#include "include/engine/error/SceneError.hpp"

AScene::AScene(const QString &name) : _name(name)
{
    _state = true;
}

AScene::~AScene()
{
}

QVector<QSharedPointer<AGameObject>> AScene::getFromLayer(int layer)
{
    QVector<QSharedPointer<AGameObject>> vector;

    for (int it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getLayer() == layer)
            vector.push_back(_objects[it]);
    }
    return vector;
}

QVector<QSharedPointer<AGameObject>> AScene::getFromID(int id)
{
    QVector<QSharedPointer<AGameObject>> vector;

    for (int it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getID() == id)
            vector.push_back(_objects[it]);
    }
    return vector;
}

QSharedPointer<AGameObject> &AScene::getFromName(const QString &name)
{
    for (int it = 0; it < _objects.size(); it++) {
        if (_objects[it]->getName() == name)
        return _objects[it];
    }
    throw SceneError("Component Name '" + name + "' not found.");
}

const QString & AScene::getName() const
{
    return _name;
}

bool AScene::update(event event)
{
    try {
        for (int it = 0; it < _objects.size(); it++) {
            _objects[it]->update(event);
        }
    }
    catch (SceneState &e) {
        _state = e.getState();
    }
    return _state;
}

void AScene::addObject(const QSharedPointer<AGameObject> &object)
{
    _objects.push_back(object);
}

void AScene::destroyGameObjectFromName(const QString &name)
{
    for (QVector<QSharedPointer<AGameObject>>::iterator it = _objects.begin(); it < _objects.end(); it++) {
        if ((*it)->getName() == name)
            _objects.erase(it);
    }
}

void AScene::destroyGameObject()
{
    _objects.clear();
}

void AScene::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        _name = json["name"].toString();
    if (json.contains("score") && json["score"].isString())
        _score = json["score"].toInt();
    if (json.contains("state") && json["state"].isString())
        _state = json["state"].toBool();
    if (json.contains("object") && json["object"].isArray()) {
        QJsonArray objArray = json["object"].toArray();
        _objects.clear();
        _objects.reserve(objArray.size());
        for (int objIndex = 0; objIndex < objArray.size(); ++objIndex) {
            QJsonObject npcObject = objArray[objIndex].toObject();
            QSharedPointer<AGameObject> obj;
            obj->read(npcObject);
            _objects.append(obj);
        }
    }
}

void AScene::write(QJsonObject &json) const
{
    json["name"] = _name;
    json["score"] = _score;
    json["state"] = _state;
    QJsonArray objectArray;
    for (int x = 0; x < _objects.size(); x++) {
        QJsonObject gameObject;
        _objects[x]->write(gameObject);
        objectArray.append(gameObject);
    }
    json["object"] = objectArray;
}

void AScene::debug()
{
    qDebug() << "Scene : " << _name << '\n' << "List of AGameObjects :" << '\n';
    for (int x = 0; x < _objects.size(); x++) {
        qDebug() << "\t" << _objects[x]->getName() << '\n';
    }
}
