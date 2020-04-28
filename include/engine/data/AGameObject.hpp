/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** GameObject Abstract class declaration
*/

#ifndef AGAMEOBJECT_HPP
#define AGAMEOBJECT_HPP

/// @file include/engine/data/AGameObject.hpp

#include <string>
#include <memory>
#include <map>
#include "AComponent.hpp"
#include "GameObjectError.hpp"

namespace wd
{
    ///
    /// GameObject Abstract class, declaration of a general GameObject
    ///
    class AGameObject {
        public:
            AGameObject(const std::string &name, int id, int layer);            ///<Constructor
                                                                                ///<
            AGameObject(wd::AGameObject &);                                     ///<Copy Constructor
                                                                                ///<
            ~AGameObject() = default;                                           ///<Destructor
                                                                                ///<

            int                 getID() const {return _id;}                     ///<Return an int as a macro corresponding to the GameObject's ID
                                                                                ///<
            const std::string   &getName() const {return _name;}                ///<Return a reference on a std::string corresponding to the GameObject's name
                                                                                ///<
            int                 getLayer() const {return _layer;}               ///<Return an int as a macro corresponding to the GameObject's Layer

            template <class Type, typename... Args>
            void addComponent(const std::string &name, Args&&... params)        ///<Add the unique_ptr on AComponent passed as parameter to the map member named _component
            {                                                                   ///<
                _component[name] = std::make_unique<Type>(std::forward<Args>(params)...);
            }

            template <class Type>
            Type &getComponent(const std::string &name)                         ///<Return a unique_ptr on type passed as template corresponding to the GameObject's component
            {                                                                   ///<
                for ( auto && component : _component ) {
                    if ( component.second->getName() == name)
                        return *static_cast<Type *>(component.second.get());
                }
                throw wd::error::GameObjectError("Component of type '" + name + "' does not exist.", getName());
                return *std::shared_ptr<Type>(nullptr);
            }

            const std::map<std::string, std::shared_ptr<wd::AComponent>> &getComponentList() const {return _component;}     ///<Return Component List
                                                                                                                            ///<
            void debug();                                                                                                   ///<Display the name of all components available
                                                                                                                            ///<

                                                                                ///<
            void                update(wd::event);                              ///<Call the update function of all IComponent in the _component map
                                                                                ///<

        protected:
            std::map<std::string, std::shared_ptr<wd::AComponent>>  _component;

        private:
            const std::string   _name;
            int                 _id;
            int                 _layer;
    };
}

#endif /* !IGAMEOBJECT_HPP */
