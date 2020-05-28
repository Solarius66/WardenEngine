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
        ///<Constructor
        AGameObject(const QString &name, int id, int layer); ///<

        ///<Copy Constructor
        AGameObject(AGameObject &); ///<

        ///<Destructor
        ~AGameObject() = default; ///<

        ///<Return an int as a macro corresponding to the GameObject's ID
        int                 getID() const {return _id;} ///<

        ///<Return a reference on a QString corresponding to the GameObject's name
        const QString   &getName() const {return _name;} ///<

        ///<Return an int as a macro corresponding to the GameObject's Layer
        int                 getLayer() const {return _layer;} ///<

        ///<Add the unique_ptr on AComponent passed as parameter to the map member named _component
        template <class Type, typename... Args>
        void addComponent(const QString &name, Args&&... params) ///<
        {
            _component[name] = QSharedPointer<Type>(new Type (std::forward<Args>(params)...));
        }

        ///<Return a unique_ptr on type passed as template corresponding to the GameObject's component
        template <class Type>
        Type &getComponent(const QString &name) ///<
        {
            for ( auto && component : _component ) {
                if ( component->getName() == name)
                    return *static_cast<Type *>(component.data());
            }
            throw GameObjectError("Component of type '" + name + "' does not exist.", getName());
            return *QSharedPointer<Type>(nullptr);
        }

        ///<Return Component List
        const QMap<QString, QSharedPointer<AComponent>> &getComponentList() const {return _component;} ///<

        ///<Load a gameobject from a .json object
        void read(const QJsonObject &json); ///<

        ///<Save a gameobject in a .json object
        void write(QJsonObject &json) const; ///<

        ///<Display the name of all components available
        void debug(); ///<

        ///<Call the update function of all IComponent in the _component map
        void update(event); ///<

    protected:
        QMap<QString, QSharedPointer<AComponent>>  _component;

    private:
        const QString       _name;
        int                 _id;
        int                 _layer;
};

#endif /* !IGAMEOBJECT_HPP */
