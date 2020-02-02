/*
** EPITECH PROJECT, 2019
** ASprite.cpp
** File description:
** ASprite member functions implementation
*/

#include <SFML/Graphics.hpp>

#include "ASprite.hpp"

wd::ASprite::ASprite()
{

}

// create the _sprite sf::Sprite from sf::Texture and sf::IntRect
void wd::ASprite::createSprite(const sf::Texture &texture, const sf::IntRect &rect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(rect);
}

void wd::ASprite::setIsActive(bool isActive)
{
    _isActive = isActive;
}

void wd::ASprite::Update(std::shared_ptr<wd::ITransform> transform)
{
    _sprite.setPosition(transform->getPosition().x, transform->getPosition().y);
    _sprite.setScale(transform->getScale().x, transform->getScale().y);
    _sprite.setRotation(transform->getRotation());
}
