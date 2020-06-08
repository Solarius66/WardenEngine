#ifndef SOUNDOBJECT_HPP
#define SOUNDOBJECT_HPP

#include <QString>

class SoundComponent
{
    public:
        SoundComponent(const QString &);
        ~SoundComponent(void);

        const QString   &getPath(void) {return (path);}
        int             getVolume(void) {return (volume);}
        bool            getLoop(void) {return (loop);}

        void            setPath(const QString &value) {path = value;}
        void            setVolue(int value) {volume = value;}
        void            setLoop(bool value) {loop = value;}

    private:
        QString         path;
        int             volume;
        bool            loop;
};

#endif // SOUNDOBJECT_HPP
