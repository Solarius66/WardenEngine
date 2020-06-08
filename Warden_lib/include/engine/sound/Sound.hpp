/*
** EPITECH PROJECT, 2019
** Sound.hpp
** File description:
** Sound Class Declaration
*/

#ifndef SOUND_H
#define SOUND_H

#include "include/engine/sound/ISound.hpp"
#include "include/engine/sound/SoundComponent.hpp"
#include <QVector>

class Sound : public ISound
{
    public:
        Sound(void);
        ~Sound(void);

        void getSound(const QSharedPointer<IScene> &) override;

    private:
        QVector <SoundComponent> list;
};

#endif // SOUND_H
