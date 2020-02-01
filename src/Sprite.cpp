/*
** EPITECH PROJECT, 2019
** Sprite.cpp
** File description:
** Sprite member functions implementation
*/

#include "Sprite.hpp"

wd::Sprite::Sprite()
{

}

// create the _sprite sf::Sprite from sf::Texture and sf::IntRect
void wd::Sprite::createSprite(const sf::Texture &texture, const sf::IntRect &rect)
{
    _sprite(texture, rect);
}

void wd::Sprite::setIsActive(bool isActive)
{
    _isActive = isActive;
}

void wd::Sprite::Update(const wd::ITransform &transform)
{
    _sprite.setPosition(transform.getPosition());
    _sprite.setScale(transform.getScale());
    _sprite.setRotation(transform.getRotation());
}
