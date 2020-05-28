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
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "IGraphicalModule.hpp"

class SFMLModule : public IGraphicalModule
{
public:
    ///<Constructor
    SFMLModule(); ///<

    ///<Destructor
    ~SFMLModule() = default; ///<

    ///<Return the title of the Window
    const QString & getTitle() const {return _title;} ///<

    ///<Draw the GameObject passed as parameter in the window
    void                draw(const QSharedPointer<AGameObject> &); ///<

    ///<Add an event to the queue when a key is pressed
    void                manageEvent(QQueue<event> &); ///<


private:
    const QString                       _title;
    QSharedPointer<sf::RenderWindow>    _window;
    sf::Font                            _font;
    sf::Clock                           _inputClock;
};

#endif /* end of include guard: GRAPHICALMODULE_HPP_ */
