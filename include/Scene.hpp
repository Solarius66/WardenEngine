/*
** EPITECH PROJECT, 2019
** Scene.hpp
** File description:
** Definition of the Scene Class
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "IScene.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Scene : public wd::IScene
    {
    public:
        Scene(const std::string &name);
        ~Scene() = default;

        // Members getter
        std::vector<IGameObject>    getFromLayer(wd::LAYER) const;
        std::vector<IGameObject>    getFromID(wd::ID) const;
        IGameObject &               getFromName(const std::string &) const;
        const std::string &         getName() const {return _name;}

        void        Update();
        Iscene &    operator+(const IGameObject &);
        void        destroyIGameObjectFromName(const std::string &);

    private:
        const std::string               _name;
        std::vector<wd::IGameObject>    _objects;
    };
}

#pragma pack(pop)

#endif /* end of include guard: SCENE_HPP_ */
