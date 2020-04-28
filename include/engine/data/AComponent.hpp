/*
** EPITECH PROJECT, 2019
** AComponent.hpp
** File description:
** Component Abstract Declaration
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

/// @file include/engine/data/AComponent.hpp

#include <string>

#include "Event.hpp"
#include "SceneState.hpp"

namespace wd
{
    ///
    /// Component Abstract, used to generalize components
    ///
    class AComponent
    {
    public:
        AComponent(const std::string &name) : _name(name) {}    ///<Constructor, take a const string as parameter
                                                                ///<
        virtual ~AComponent() = default;                                  ///<Destructor
                                                                ///<

        virtual void update(wd::event) {}                 ///<Call the update() of the component
                                                        ///<
        const std::string &getName() {return _name;}    ///<Return _name variable
                                                        ///<

    protected:
        const std::string _name;
    };
}

#endif /* end of include guard: ACOMPONENT_HPP_ */
