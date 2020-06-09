#ifndef SOUNDOBJECT_HPP
#define SOUNDOBJECT_HPP

#include <QString>

class SoundObject
{
    public:
        SoundObject(const QString &, int, bool, bool);
        ~SoundObject();

        const QString   &getPath()  const {return (path);}
        int             getVolume() const {return (volume);}
        bool            getLoop()   const {return (loop);}
        bool            getPLay()   const {return (play);}

        void            setPath(const QString &value) {path = value;}
        void            setVolue(int value) {volume = value;}
        void            setLoop(bool value) {loop = value;}
        void            setPlay(bool value) {play = value;}
private:
        QString         path;
        int             volume;
        bool            loop;
        bool            play;
};

#endif // SOUNDOBJECT_HPP
