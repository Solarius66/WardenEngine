#ifndef ISOUND_HPP
#define ISOUND_HPP

#include <QSharedPointer>
#include "include/engine/data/IScene.hpp"

class ISound
{
    public:
        ISound() = default;
        virtual ~ISound() = default;

        virtual void getSound(const QSharedPointer<IScene> &);
};

#endif // ISOUND_HPP
