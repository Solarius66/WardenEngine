/*
** EPITECH PROJECT, 2019
** TextRenderer.cpp
** File description:
** TextRenderer Class Implementation
*/

#include "include/engine/data/TextRenderer.hpp"

TextRenderer::TextRenderer(const QString & str)
:  AComponent("TextRenderer")
{
    _str = str;
}

TextRenderer::~TextRenderer()
{

}

void TextRenderer::setText(const QString &str)
{
    _str = str;
}

void TextRenderer::addText(const QString &str)
{
    _str += str;
}

void TextRenderer::removeText(int value)
{
    for (int x = 0; x < value; x++)
        if (_str.size() > 0)
            _str.remove(_str.length() - 1);
}
