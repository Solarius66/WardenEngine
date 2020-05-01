/*
** EPITECH PROJECT, 2019
** IDisplay.hpp
** File description:
** Display Interface Declaration
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

/// @file include/engine/display/IDisplay.hpp

#include <queue>

#include "AGameObject.hpp"
#include "IScene.hpp"

namespace wd
{
    ///
    /// Display Interface Declaration
    ///
    class IDisplay
    {
    public:
        IDisplay() = default;               ///<Constructor
                                            ///<
        virtual ~IDisplay() = default;      ///<Destructor
                                            ///<

        virtual void draw(const std::shared_ptr<wd::IScene> &, std::queue<wd::event> &) = 0;        ///<Display every GameObject of a scene and get each input of the player
                                                                                                ///<
        virtual void drawGameObject(const std::shared_ptr<wd::AGameObject>) = 0;                ///<Display only 1 GameObject
                                                                                                ///<

    protected:
        virtual void drawLayer(const std::vector<std::shared_ptr<wd::AGameObject>> &) const = 0;    ///<Display every GameObject of a Layer of a Scene
                                                                                                    ///<
    };
}

#endif /* end of include guard: IDISPLAY_HPP_ */
