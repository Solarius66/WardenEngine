/*
** EPITECH PROJECT, 2019
** Sound.hpp
** File description:
** Sound Class Declaration
*/

#ifndef SOUND_H
#define SOUND_H

#include "include/engine/sound/ISound.hpp"
#include "include/engine/sound/SoundObject.hpp"
#include <QVector>

class Sound : public ISound
{
    public:
        Sound();
        ~Sound();

        const QVector <QSharedPointer<SoundObject>> &getSound(const QSharedPointer<IScene> &) override;
};

#endif // SOUND_H
