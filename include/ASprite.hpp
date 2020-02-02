/*
** EPITECH PROJECT, 2019
** ASprite.hpp
** File description:
** Declaration of Sprite Abstract Class
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include "ISprite.hpp"

#pragma pack(push, 1)

namespace wd
{
    class ASprite : public wd::ISprite
    {
    public:
        ASprite();
        ~ASprite() = default;

        //members getter
        const sf::Sprite &  getSprite() const {return _sprite;}
        const bool &        getIsActive() const {return _isActive;}

        //members setter
        void createSprite(const sf::Texture &, const sf::IntRect &);
        void setIsActive(bool);

        void Update(const wd::ITransform &);

    private:
        sf::Sprite _sprite;
        bool _isActive = true;
    };
}

#pragma pack(pop)

#endif /* end of include guard: SPRITE_HPP_ */
