/*
** EPITECH PROJECT, 2019
** SoundObject.hpp
** File description:
** SoundObject class Declaration
*/

#ifndef SOUNDOBJECT_HPP
#define SOUNDOBJECT_HPP

#include <QString>

class SoundObject
{
    public:
        SoundObject(const QString &, int, bool, bool);
        ~SoundObject();

        const QString   &getPath()  const {return (_path);}
        int             getVolume() const {return (_volume);}
        bool            getLoop()   const {return (_loop);}
        bool            getPLay()   const {return (_play);}

        void            setPath(const QString &path) {_path = path;}
        void            setVolue(int volume) {_volume = volume;}
        void            setLoop(bool loop) {_loop = loop;}
        void            setPlay(bool play) {_play = play;}

    private:
        QString         _path;
        int             _volume;
        bool            _loop;
        bool            _play;
};

#endif // SOUNDOBJECT_HPP
