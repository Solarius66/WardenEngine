/*
** EPITECH PROJECT, 2019
** SceneState.hpp
** File description:
** SceneState Class Declaration
*/

#ifndef SCENESTATE_HPP_
#define SCENESTATE_HPP_

/// @file include/engine/data/SceneState.hpp

#include <QException>

class SceneState : public QException
{
public:
    SceneState(bool state = true) {_state = state;}
    ~SceneState() = default;

    bool getState() {return _state;}

private:
    bool _state;
};

#endif /* end of include guard: SCENESTATE_HPP_ */
