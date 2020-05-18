/*
** EPITECH PROJECT, 2019
** MeshRenderer.cpp
** File description:
** MeshRenderer Class Implementation
*/

#include "include/engine/data/MeshRenderer.hpp"

MeshRenderer::MeshRenderer(const QString & text, const QString &graph2d, const QString &graph3d)
:  AComponent("MeshRenderer"), _text(text), _graph2d(graph2d), _graph3d(graph3d)
{
}

MeshRenderer::~MeshRenderer()
{

}
