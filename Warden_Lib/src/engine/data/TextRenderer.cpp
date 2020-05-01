/*
** EPITECH PROJECT, 2019
** TextRenderer.cpp
** File description:
** TextRenderer Class Implementation
*/

#include "TextRenderer.hpp"

wd::TextRenderer::TextRenderer(const std::string & str)
:  AComponent("TextRenderer")
{
    _str = str;
}

wd::TextRenderer::~TextRenderer()
{

}

void wd::TextRenderer::setText(const std::string &str)
{
    _str = str;
}

void wd::TextRenderer::addText(const std::string &str)
{
    _str += str;
}

void wd::TextRenderer::removeText(int value)
{
    for (int x = 0; x < value; x++)
        if (_str.size() > 0)
            _str.pop_back();
}
