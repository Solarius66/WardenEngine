/*
** EPITECH PROJECT, 2019
** SFMLModule.hpp
** File description:
** SFMLModule Class Declaration
*/

#ifndef SFMLMODULE_HPP_
#define SFMLMODULE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <queue>

#include "IGraphicalModule.hpp"

namespace wd
{
    class SFMLModule : public wd::IGraphicalModule
    {
    public:
        SFMLModule();               ///<Constructor
                                    ///<
        ~SFMLModule() = default;    ///<Destructor
                                    ///<

        const std::string & getTitle() const {return _title;}                   ///<Return the title of the Window
                                                                                ///<
        void                draw(const std::shared_ptr<wd::AGameObject> &);     ///<Draw the GameObject passed as parameter in the window
                                                                                ///<
        void                manageEvent(std::queue<wd::event> &);               ///<Add an event to the queue when a key is pressed
                                                                                ///<

    private:
        const std::string                   _title;
        std::unique_ptr<sf::RenderWindow>   _window;
        sf::Font                            _font;
        sf::Clock                           _inputClock;
    };
}

#endif /* end of include guard: GRAPHICALMODULE_HPP_ */
