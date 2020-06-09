#ifndef SOUNDCOMPONENT_HPP
#define SOUNDCOMPONENT_HPP

#include <QVector>
#include <QSharedPointer>

#include "include/engine/data/AComponent.hpp"
#include "include/engine/sound/SoundObject.hpp"
#include "include/engine/Event.hpp"

class SoundComponent : public AComponent
{
    public:
        SoundComponent();

        virtual void update(enum event) {};
        QVector<QSharedPointer<SoundObject>> toPlay();

    private:
        QVector<QSharedPointer<SoundObject>> _list;

};

#endif // SOUNDCOMPONENT_HPP
