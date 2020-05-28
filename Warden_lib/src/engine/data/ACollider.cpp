/*
** EPITECH PROJECT, 2019
** ACollider.cpp
** File description:
** ACollider Class Implementation
*/

#include <QDebug>

#include "include/engine/data/ACollider.hpp"
#include "include/engine/data/Transform.hpp"

ACollider::ACollider(QSharedPointer<AGameObject> thisGameObject, const QSharedPointer<IScene> &scene)
: AComponent("ACollider")
{
    _this = thisGameObject;
    _scene = scene;
}

ACollider::~ACollider()
{

}

void ACollider::update(event _event)
{
    static_cast<void>(_event);
    for (int x = 0; x < _scene->getObjects().size(); x++) {
        if (_this->getName() == _scene->getObjects()[x]->getName())
            continue;
        if ((_this->getComponent<Transform>("Transform").getPosition().x + _this->getComponent<Transform>("Transform").getSize().x) >
        (_scene->getObjects()[x]->getComponent<Transform>("Transform").getPosition().x) &&
        (_this->getComponent<Transform>("Transform").getPosition().y + _this->getComponent<Transform>("Transform").getSize().y) >
        (_scene->getObjects()[x]->getComponent<Transform>("Transform").getPosition().y) &&
        (_scene->getObjects()[x]->getComponent<Transform>("Transform").getPosition().x + _scene->getObjects()[x]->getComponent<Transform>("Transform").getSize().x) >
        (_this->getComponent<Transform>("Transform").getPosition().x) &&
        (_scene->getObjects()[x]->getComponent<Transform>("Transform").getPosition().y + _scene->getObjects()[x]->getComponent<Transform>("Transform").getSize().y) >
        (_this->getComponent<Transform>("Transform").getPosition().y)) {
            _isCollide[_scene->getObjects()[x]->getName()] = false;
            if (_isCollide[_scene->getObjects()[x]->getName()] == false) {
                onTriggerEnter(_scene->getObjects()[x]);
                _isCollide[_scene->getObjects()[x]->getName()] = true;
            }
            if (_isCollide[_scene->getObjects()[x]->getName()] == true)
                onTriggerStay(_scene->getObjects()[x]);
        } else if (_isCollide[_scene->getObjects()[x]->getName()] == true) {
            onTriggerExit(_scene->getObjects()[x]);
            _isCollide.remove(_scene->getObjects()[x]->getName());
        }
    }
}

void ACollider::read(const QJsonObject &json)
{

}

void ACollider::write(QJsonObject &json) const
{
    json["collide"] = false;
    json["this"] = _this->getName();
    json["scene"] = _scene->getName();
}

void ACollider::onTriggerEnter(QSharedPointer<AGameObject> other)
{
    qDebug() << "Trigger Enter with " << other->getName() << '\n';
}

void ACollider::onTriggerStay(QSharedPointer<AGameObject> other)
{
    qDebug() << "Trigger Stay with " << other->getName() << '\n';
}

void ACollider::onTriggerExit(QSharedPointer<AGameObject> other)
{
    qDebug() << "Trigger Exit with " << other->getName() << '\n';
}
