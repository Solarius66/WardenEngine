/*
** EPITECH PROJECT, 2020
** Tile
** File description:
** Tile class member functions implementation
*/

#include <string>
#include "AGameObject.hpp"
#include "Enums.hpp"
#include "Tile.hpp"

wd::Tile::Tile(const std::string &name) : AGameObject(name, wd::WALL)
{
}