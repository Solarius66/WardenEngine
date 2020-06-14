#ifndef ISOUND_HPP
#define ISOUND_HPP

#include <QSharedPointer>
#include "include/engine/data/IScene.hpp"
#include "include/engine/sound/SoundObject.hpp"

class ISound
{
    public:
        ISound() = default;
        virtual ~ISound() = default;

        virtual const QVector <QSharedPointer<SoundObject>> &getSound(const QSharedPointer<IScene> &);
};

#endif // ISOUND_HPP
