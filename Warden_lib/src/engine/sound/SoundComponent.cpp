#include "include/engine/sound/SoundComponent.hpp"

SoundComponent::SoundComponent(): AComponent("SoundComponent")
{}

QVector<QSharedPointer<SoundObject>> SoundComponent::toPlay()
{
    QVector <QSharedPointer<SoundObject>> tmp;

    for (auto && it : _list)
        if (it->getPLay()) {
            tmp.append(it);
            it->setPlay(false);
        }
    return (tmp);
}
