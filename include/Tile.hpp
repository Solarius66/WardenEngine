/*
** EPITECH PROJECT, 2020
** Tile
** File description:
** Tile class declaration
*/

#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include "AGameObject.hpp"
#include "Enums.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Tile : public AGameObject
    {
        public:
            Tile(const std::string &name = "basicTile");
            ~Tile() = default;
    };
}

#pragma pack(pop)

#endif /* !TILE_HPP */