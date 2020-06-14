/*
** EPITECH PROJECT, 2019
** Sound.hpp
** File description:
** Sound Class Declaration
*/

#include "include/engine/sound/Sound.hpp"
#include "include/engine/data/IScene.hpp"
#include <include/engine/sound/SoundComponent.hpp>

Sound::Sound()
{}

const QVector <QSharedPointer<SoundObject>> &Sound::getSound(const QSharedPointer<IScene> &scene)
{
    QVector <QSharedPointer<SoundObject>> tmp;

    for (auto && it : scene->getObjects()) {
        try {
            it->getComponent<SoundComponent>("SoundComponent");
            tmp.append(it->getComponent<SoundComponent>("SoundComponent").toPlay());
        } catch (GameObjectError &e) {}
    }
    return (tmp);
}
