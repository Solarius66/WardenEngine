/*
** EPITECH PROJECT, 2019
** ISprite.hpp
** File description:
** Declaration of Sprite Interface
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include <SFML/Graphics.hpp>

#include "ITransform.hpp"

namespace wd
{
    class ISprite
    {
    public:
        ISprite() = delete;
        virtual ~ISprite();

        virtual const sf::Sprite &  getSprite() const = 0;
        virtual const bool &        getIsActive() const = 0;

        virtual void createSprite(const sf::Texture &, const sf::IntRect &) = 0;
        virtual void setIsActive(bool) = 0;

        virtual void Update(const wd::ITransform &) = 0;
    };
}

#endif /* end of include guard: ISPRITE_HPP_ */
