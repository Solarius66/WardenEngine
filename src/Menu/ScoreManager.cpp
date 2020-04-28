/*
** EPITECH PROJECT, 2019
** ScoreManager.cpp
** File description:
** ScoreManager Class Implementation
*/

#include <memory>

#include "TextRenderer.hpp"
#include "ScoreManager.hpp"

wd::ScoreManager::ScoreManager(int value, const std::shared_ptr<AGameObject> &obj) : AComponent("ScoreManager")
{
    obj->getComponent<wd::TextRenderer>("TextRenderer").setText(std::to_string(value));
}
