/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GameObject Abstract class declaration
*/

#ifndef AGAMEOBJECT_HPP
#define AGAMEOBJECT_HPP

/// @file include/engine/data/AGameObject.hpp

#include <QSharedPointer>
#include <QMap>

#include "include/engine/error/GameObjectError.hpp"
#include "include/engine/data/AComponent.hpp"

///
/// GameObject Abstract class, declaration of a general GameObject
///
class AGameObject {
    public:
        AGameObject(const QString &name, int id, int layer);            ///<Constructor
                                                                            ///<
        AGameObject(AGameObject &);                                     ///<Copy Constructor
                                                                            ///<
        ~AGameObject() = default;                                           ///<Destructor
                                                                            ///<

        int                 getID() const {return _id;}                     ///<Return an int as a macro corresponding to the GameObject's ID
                                                                            ///<
        const QString   &getName() const {return _name;}                ///<Return a reference on a QString corresponding to the GameObject's name
                                                                            ///<
        int                 getLayer() const {return _layer;}               ///<Return an int as a macro corresponding to the GameObject's Layer

        template <class Type, typename... Args>
        void addComponent(const QString &name, Args&&... params)        ///<Add the unique_ptr on AComponent passed as parameter to the map member named _component
        {                                                                   ///<
            _component[name] = QSharedPointer<Type>(new Type (std::forward<Args>(params)...));
        }

        template <class Type>
        Type &getComponent(const QString &name)                         ///<Return a unique_ptr on type passed as template corresponding to the GameObject's component
        {                                                                   ///<
            for ( auto && component : _component ) {
                if ( component->getName() == name)
                    return *static_cast<Type *>(component.data());
            }
            throw GameObjectError("Component of type '" + name + "' does not exist.", getName());
            return *QSharedPointer<Type>(nullptr);
        }

        const QMap<QString, QSharedPointer<AComponent>> &getComponentList() const {return _component;}     ///<Return Component List
                                                                                                                        ///<
        void debug();                                                                                                   ///<Display the name of all components available
                                                                                                                        ///<

                                                                            ///<
        void                update(event);                              ///<Call the update function of all IComponent in the _component map
                                                                            ///<

    protected:
        QMap<QString, QSharedPointer<AComponent>>  _component;

    private:
        const QString       _name;
        int                 _id;
        int                 _layer;
};

#endif /* !IGAMEOBJECT_HPP */
