/*
** EPITECH PROJECT, 2019
** Display.hpp
** File description:
** Display Class Declaration
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

/// @file include/engine/display/Display.hpp

#include <vector>

#include "IDisplay.hpp"
#include "Event.hpp"
#include "IGraphicalModule.hpp"

namespace wd
{
    ///
    /// Display Class Declaration
    ///
    class Display : public wd::IDisplay
    {
    public:
        Display();      ///<Constructor
                        ///<
        ~Display();     ///<Destructor
                        ///<

        void draw(const std::shared_ptr<wd::IScene> &, std::queue<wd::event> &);      ///<Display every GameObject of a scene and get each input of the player
                                                                                    ///<
        void drawGameObject(const std::shared_ptr<wd::AGameObject>);                ///<Display only 1 GameObject
                                                                                    ///<
    private:
        void drawLayer(const std::vector<std::shared_ptr<wd::AGameObject>> &) const;    ///<Display every GameObject of a Layer of a Scene
                                                                                        ///<
        std::unique_ptr<wd::IGraphicalModule> _graphicalLib;
    };
}

#endif /* end of include guard: DISPLAY_HPP_ */
