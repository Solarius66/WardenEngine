/*
** EPITECH PROJECT, 2019
** Enums.cpp
** File description:
** Enums functions implementation
*/

#include "Enums.hpp"

wd::LAYER &operator--(wd::LAYER &layer)
{
    switch (layer) {
        case wd::LAYER::HUD : return layer = wd::LAYER::BACKGROUND;
        case wd::LAYER::FOREGROUND : return layer = wd::LAYER::HUD;
        case wd::LAYER::BACKGROUND : return layer = wd::LAYER::FOREGROUND;
    }
    return layer;
}
