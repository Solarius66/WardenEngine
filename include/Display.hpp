/*
** EPITECH PROJECT, 2019
** Display.hpp
** File description:
** Definition of the Display Class
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "IDisplay.hpp"

#pragma pack(push, 1)

namespace wd
{
    class Display : public wd::IDisplay
    {
    public:
        Display();
        ~Display() = default;

        void    draw(const wd::IScene &);
        void    drawGameObject(const std::shared_ptr<wd::IGameObject> &);

    private:
        void    drawLayer(const std::vector<std::shared_ptr<wd::IGameObject>> &);

        std::unique_ptr<IWindow> _window;
    };
}

#pragma pack(pop)

#endif /* end of include guard: DISPLAY_HPP_ */
