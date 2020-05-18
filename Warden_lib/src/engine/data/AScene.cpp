/*
** EPITECH PROJECT, 2019
** AScene.cpp
** File description:
** AScene Class Implementation
*/

#include <QDebug>

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

void AScene::debug()
{
    qDebug() << "Scene : " << _name << '\n' << "List of AGameObjects :" << '\n';
    for (int x = 0; x < _objects.size(); x++) {
        qDebug() << "\t" << _objects[x]->getName() << '\n';
    }
}
