/*
** EPITECH PROJECT, 2019
** SoundObject.hpp
** File description:
** SoundObject Class
*/

#include "include/engine/sound/SoundObject.hpp"

SoundObject::SoundObject(const QString &path, int volume = 50, bool loop = false, bool play = false)
{
    _path = path;
    _volume = volume;
    _loop = loop;
    _play = play;
}
