/*
** EPITECH PROJECT, 2019
** MeshRenderer.cpp
** File description:
** MeshRenderer Class Implementation
*/

#include "MeshRenderer.hpp"

wd::MeshRenderer::MeshRenderer(const std::string & text, const std::string &graph2d, const std::string &graph3d)
:  AComponent("MeshRenderer"), _text(text), _graph2d(graph2d), _graph3d(graph3d)
{
}

wd::MeshRenderer::~MeshRenderer()
{

}
