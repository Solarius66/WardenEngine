/*
** EPITECH PROJECT, 2019
** AScene.hpp
** File description:
** AScene Class Declaration
*/

#ifndef ASCENE_HPP_
#define ASCENE_HPP_

/// @file include/engine/data/AScene.hpp

#include <QSharedPointer>
#include <QVector>

#include "include/engine/data/AGameObject.hpp"
#include "include/engine/data/IScene.hpp"

///
/// AScene Class, contain the AGameObject Vector and the Name of the scene
///
class AScene : public IScene
{
public:
    AScene(const QString &);    ///<Constructor
                                    ///<
    ~AScene();                      ///<Destructor
                                    ///<

    QVector<QSharedPointer<AGameObject>>   getFromLayer(int);                      ///<Return a vector containing all AGameObjects from a Layer specified as parameter
                                                                                            ///<
    QVector<QSharedPointer<AGameObject>>   getFromID(int);                         ///<Return a vector containing all AGameObjects from an ID specified as parameter
                                                                                            ///<
    QSharedPointer<AGameObject> &              getFromName(const QString &);       ///<Return a Shared_ptr pointing to a AGameObject which name is specified as parameter
                                                                                            ///<
    QVector<QSharedPointer<AGameObject>>   getObjects() {return _objects;}         ///<Return the vector of AGameObject
                                                                                            ///<
    const QString &                             getName() const;                        ///<Return the name of the AScene
                                                                                            ///<
    virtual int                                     getScore() {return _score;}             ///<Return the Score of the Scene
                                                                                            ///<
    virtual void                                    setScore(int score) {_score = score;}   ///<Return the Score of the Scene
                                                                                            ///<

    bool    update(event);                                                          ///<Call update() of every AGameObject contained in the IAScene
                                                                                        ///<
    void    addObject(const QSharedPointer<AGameObject> &);                        ///<Add a AGameObject to the vector of the AScene
                                                                                        ///<
    void    destroyGameObjectFromName(const QString &);                             ///<Remove a AGameObject from the vector, which name is specified as parameter
                                                                                        ///<
    void    destroyGameObject();                                                        ///<Remove a AGameObject from the vector, which name is specified as parameter
                                                                                        ///<
    virtual void reset() {}                                                             ///<Reset the scene as made in the constructor
                                                                                        ///<

    void    debug();    ///<Display Name of every AGameObject contained in the AScene (Used for debugging)
                        ///<

protected:
    QVector<QSharedPointer<AGameObject>>        _objects;   ///<Vector of the AGameObject
                                                                ///<
    bool                                            _state;     ///<Is the scene running
                                                                ///<
private:
    const QString                                   _name;      ///<Name of the AScene
                                                                ///<
    int                                             _score = 0; ///<Score of the Scene
                                                                ///<
};

#endif /* end of include guard: ASCENE_HPP_ */
