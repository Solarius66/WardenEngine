/*
** EPITECH PROJECT, 2020
** Enums
** File description:
** LAYER and ID enum declaration
*/

#ifndef ENUMS_HPP
#define ENUMS_HPP

namespace wd
{
    // Layer enum declaration for display order, could be HUD, FOREGROUND or BACKGROUND
    enum LAYER
    {
        HUD,
        FOREGROUND,
        BACKGROUND
    };

    // ID enum declaration for object type definition, could be NOTHING, PLAYER, ENEMY, ITEM or SYSTEM
    enum ID
    {
        NOTHING,
        PLAYER,
        ENEMY,
        ITEM,
        SYSTEM
    };
}

#endif /* !ENUMS_HPP */