/*
** EPITECH PROJECT, 2019
** IScene.hpp
** File description:
** Definition of the Scene Interface
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <vector>
#include <string>

namespace wd
{
    class IScene
    {
    public:
        IScene() = delete;
        virtual ~IScene();

        // Members getter
        virtual std::vector<IGameObject>    getFromLayer(wd::LAYER) const = 0;
        virtual std::vector<IGameObject>    getFromID(wd::ID) const = 0;
        virtual IGameObject &               getFromName(const std::string &) const = 0;
        virtual const std::string &         getName() const = 0;

        virtual void                        Update() = 0;
        virtual IScene &                    operator+(const IGameObject &) = 0;
        virtual void                        destroyIGameObjectFromName(const std::string &) = 0;
    };
}

std::ostream operator<<(std::ostream &, const wd::IScene &);

#endif /* end of include guard: ISCENE_HPP_ */
