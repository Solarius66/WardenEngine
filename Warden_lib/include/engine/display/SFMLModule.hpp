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

#include "IGraphicalModule.hpp"

class SFMLModule : public IGraphicalModule
{
public:
    SFMLModule();               ///<Constructor
                                ///<
    ~SFMLModule() = default;    ///<Destructor
                                ///<

    const QString & getTitle() const {return _title;}                   ///<Return the title of the Window
                                                                            ///<
    void                draw(const QSharedPointer<AGameObject> &);     ///<Draw the GameObject passed as parameter in the window
                                                                            ///<
    void                manageEvent(QQueue<event> &);               ///<Add an event to the queue when a key is pressed
                                                                            ///<

private:
    const QString                       _title;
    QSharedPointer<sf::RenderWindow>    _window;
    sf::Font                            _font;
    sf::Clock                           _inputClock;
};

#endif /* end of include guard: GRAPHICALMODULE_HPP_ */
