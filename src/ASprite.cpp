/*
** EPITECH PROJECT, 2019
** ASprite.cpp
** File description:
** ASprite member functions implementation
*/

#include "ASprite.hpp"

wd::ASprite::ASprite()
{

}

// create the _sprite sf::Sprite from sf::Texture and sf::IntRect
void wd::ASprite::createSprite(const sf::Texture &texture, const sf::IntRect &rect)
{
    _sprite(texture, rect);
}

void wd::ASprite::setIsActive(bool isActive)
{
    _isActive = isActive;
}

void wd::ASprite::Update(const wd::ITransform &transform)
{
    _sprite.setPosition(transform.getPosition());
    _sprite.setScale(transform.getScale());
    _sprite.setRotation(transform.getRotation());
}
