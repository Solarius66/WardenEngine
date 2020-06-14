/*
** EPITECH PROJECT, 2019
** SFMLModule.cpp
** File description:
** SFMLModule Class Implementation
*/

#include <iostream>

#include "include/engine/display/SFMLModule.hpp"
#include "include/engine/data/MeshRenderer.hpp"
#include "include/engine/data/Transform.hpp"
#include "include/engine/data/TextRenderer.hpp"

SFMLModule::SFMLModule() : _title("SFMLWindow")
{
    _window = QSharedPointer<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(672, 864), "Arcade"));
    _window->setFramerateLimit(60);
    _window->clear();
    _font.loadFromFile("./assets/font.ttf");
}

void SFMLModule::draw(const QSharedPointer<AGameObject> &gameObject)
{
    sf::Texture texture;
    try {
        gameObject->getComponent<MeshRenderer>("MeshRenderer");
        if (texture.loadFromFile(gameObject->getComponent<MeshRenderer>("MeshRenderer").get2dGraph().toStdString()) == false)
            std::cout << "Texture not Found." << std::endl;
        sf::Sprite sprite(texture);
        sprite.setPosition(gameObject->getComponent<Transform>("Transform").getPosition().x * 32 + 16, gameObject->getComponent<Transform>("Transform").getPosition().y * 32 + 16);
        sprite.setRotation(gameObject->getComponent<Transform>("Transform").getRotation().z);
        sprite.setOrigin(gameObject->getComponent<Transform>("Transform").getSize().x * 16, gameObject->getComponent<Transform>("Transform").getSize().y * 16);
        _window->draw(sprite);
    }
    catch (GameObjectError &e) {}
    try {
        gameObject->getComponent<TextRenderer>("TextRenderer");
        sf::Text text(gameObject->getComponent<TextRenderer>("TextRenderer").getText().toStdString(), _font, 32);
        text.setPosition(gameObject->getComponent<Transform>("Transform").getPosition().x * 32, gameObject->getComponent<Transform>("Transform").getPosition().y * 32);
        text.setFillColor(sf::Color::White);
        _window->draw(text);
    }
    catch (GameObjectError &e) {}
}

void SFMLModule::manageEvent(QQueue<event> &event)
{
    _window->display();
    _window->clear();
    sf::Event Event;
    while (_window->pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed) {
            _window->close();
            event.enqueue(CLOSED_WINDOW);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _window->close();
        event.enqueue(CLOSED_WINDOW);
    }
    if (_inputClock.getElapsedTime().asMilliseconds() <= 75) {
        event.enqueue(UNKNOWN);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Unknown)) {event.enqueue(UNKNOWN);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {event.enqueue(A);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {event.enqueue(B);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {event.enqueue(C);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {event.enqueue(D);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {event.enqueue(E);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {event.enqueue(F);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {event.enqueue(G);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {event.enqueue(H);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {event.enqueue(I);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {event.enqueue(J);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {event.enqueue(K);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {event.enqueue(L);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {event.enqueue(M);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {event.enqueue(N);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {event.enqueue(O);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {event.enqueue(P);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {event.enqueue(Q);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {event.enqueue(R);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {event.enqueue(S);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {event.enqueue(T);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {event.enqueue(U);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {event.enqueue(V);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {event.enqueue(W);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {event.enqueue(X);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {event.enqueue(Y);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {event.enqueue(Z);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {event.enqueue(NUM0);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {event.enqueue(NUM1);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {event.enqueue(NUM2);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {event.enqueue(NUM3);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {event.enqueue(NUM4);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {event.enqueue(NUM5);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {event.enqueue(NUM6);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {event.enqueue(NUM7);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {event.enqueue(NUM8);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {event.enqueue(NUM9);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {event.enqueue(ESCAPE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {event.enqueue(SPACE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {event.enqueue(LCONTROL);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {event.enqueue(LSHIFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {event.enqueue(LALT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {event.enqueue(RCONTROL);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {event.enqueue(RSHIFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) {event.enqueue(RALT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {event.enqueue(BACKSPACE);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {event.enqueue(TAB);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {event.enqueue(ENTER);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {event.enqueue(PAGEUP);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {event.enqueue(PAGEDOWN);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {event.enqueue(LEFT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {event.enqueue(RIGHT);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {event.enqueue(UP);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {event.enqueue(DOWN);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {event.enqueue(F1);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {event.enqueue(F2);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {event.enqueue(F3);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {event.enqueue(F4);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {event.enqueue(F5);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {event.enqueue(F6);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)) {event.enqueue(F7);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8)) {event.enqueue(F8);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) {event.enqueue(F9);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) {event.enqueue(F10);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {event.enqueue(F11);}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {event.enqueue(F12);}
    event.enqueue(UNKNOWN);
    _inputClock.restart();
}

void SFMLModule::playSound(const QVector<QSharedPointer<SoundObject>> &vec)
{
    sf::Music music;

    for (auto && it : vec) {
        music.setVolume(it->getVolume());
        music.setLoop(it->getLoop());
        if (!music.openFromFile(it->getPath().toStdString()))
            std::cerr << it->getPath().toStdString() << ": No such file or directory." << std::endl;
        music.play();
    }
}
