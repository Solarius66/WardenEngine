/*
** EPITECH PROJECT, 2019
** SFMLModule.cpp
** File description:
** SFMLModule Class Implementation
*/

#include <iostream>

#include "MeshRenderer.hpp"
#include "TextRenderer.hpp"
#include "Transform.hpp"
#include "SFMLModule.hpp"
#include "GameObjectError.hpp"

wd::SFMLModule::SFMLModule() : _title("SFMLWindow")
{
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(672, 864), "Arcade");
    _window->setFramerateLimit(60);
    _window->clear();
    _font.loadFromFile("./assets/font.ttf");
}

void wd::SFMLModule::draw(const std::shared_ptr<wd::AGameObject> &gameObject)
{
    sf::Texture texture;
    try {
        gameObject->getComponent<wd::MeshRenderer>("MeshRenderer");
        if (texture.loadFromFile(gameObject->getComponent<wd::MeshRenderer>("MeshRenderer").get2dGraph()) == false)
            std::cout << "Texture not Found." << std::endl;
        sf::Sprite sprite(texture);
        sprite.setPosition(gameObject->getComponent<wd::Transform>("Transform").getPosition().x * 32 + 16, gameObject->getComponent<wd::Transform>("Transform").getPosition().y * 32 + 16);
        sprite.setRotation(gameObject->getComponent<wd::Transform>("Transform").getRotation().z);
        sprite.setOrigin(gameObject->getComponent<wd::Transform>("Transform").getSize().x * 16, gameObject->getComponent<wd::Transform>("Transform").getSize().y * 16);
        _window->draw(sprite);
    }
    catch (wd::error::GameObjectError &e) {}
    try {
        gameObject->getComponent<wd::TextRenderer>("TextRenderer");
        sf::Text text(gameObject->getComponent<wd::TextRenderer>("TextRenderer").getText(), _font, 32);
        text.setPosition(gameObject->getComponent<wd::Transform>("Transform").getPosition().x * 32, gameObject->getComponent<wd::Transform>("Transform").getPosition().y * 32);
        text.setFillColor(sf::Color::White);
        _window->draw(text);
    }
    catch (wd::error::GameObjectError &e) {}
}

void wd::SFMLModule::manageEvent(std::queue<wd::event> &event)
{
    _window->display();
    _window->clear();
    sf::Event Event;
    while (_window->pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed) {
            _window->close();
            event.push(wd::CLOSED_WINDOW);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        event.push(wd::CLOSED_WINDOW);
    }
    if (_inputClock.getElapsedTime().asMilliseconds() <= 75) {
        event.push(wd::UNKNOWN);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) {event.push(wd::UNKNOWN);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {event.push(wd::A);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {event.push(wd::B);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {event.push(wd::C);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {event.push(wd::D);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {event.push(wd::E);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {event.push(wd::F);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {event.push(wd::G);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {event.push(wd::H);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {event.push(wd::I);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {event.push(wd::J);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {event.push(wd::K);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {event.push(wd::L);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {event.push(wd::M);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {event.push(wd::N);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {event.push(wd::O);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {event.push(wd::P);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {event.push(wd::Q);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {event.push(wd::R);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {event.push(wd::S);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {event.push(wd::T);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {event.push(wd::U);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {event.push(wd::V);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {event.push(wd::W);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {event.push(wd::X);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {event.push(wd::Y);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {event.push(wd::Z);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {event.push(wd::NUM0);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {event.push(wd::NUM1);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {event.push(wd::NUM2);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {event.push(wd::NUM3);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {event.push(wd::NUM4);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {event.push(wd::NUM5);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {event.push(wd::NUM6);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {event.push(wd::NUM7);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {event.push(wd::NUM8);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {event.push(wd::NUM9);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {event.push(wd::ESCAPE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {event.push(wd::SPACE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {event.push(wd::LCONTROL);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {event.push(wd::LSHIFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {event.push(wd::LALT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {event.push(wd::RCONTROL);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {event.push(wd::RSHIFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) {event.push(wd::RALT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {event.push(wd::BACKSPACE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {event.push(wd::TAB);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {event.push(wd::ENTER);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {event.push(wd::PAGEUP);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {event.push(wd::PAGEDOWN);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {event.push(wd::LEFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {event.push(wd::RIGHT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {event.push(wd::UP);_window->close();}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {event.push(wd::DOWN);_window->close();}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {event.push(wd::F1);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {event.push(wd::F2);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {event.push(wd::F3);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {event.push(wd::F4);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {event.push(wd::F5);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {event.push(wd::F6);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)) {event.push(wd::F7);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8)) {event.push(wd::F8);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) {event.push(wd::F9);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) {event.push(wd::F10);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {event.push(wd::F11);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {event.push(wd::F12);}
    event.push(wd::UNKNOWN);
    _inputClock.restart();
}
