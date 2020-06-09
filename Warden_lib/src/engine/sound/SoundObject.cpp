/*
** EPITECH PROJECT, 2019
** SoundComponent.hpp
** File description:
** SoundComponent Class Declaration
*/

#include "include/engine/sound/SoundObject.hpp"

SoundObject::SoundObject(const QString &_path, int _volume = 50, bool _loop = false, bool _play = false)
{
    path = _path;
    volume = _volume;
    loop = _loop;
    play = _play;
}
