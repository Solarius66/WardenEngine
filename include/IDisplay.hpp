/*
** EPITECH PROJECT, 2019
** IDisplay.hpp
** File description:
** Definition of the Display Interface
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <vector>

#include "Enums.hpp"
#include "IWindow.hpp"
#include "IData.hpp"

namespace wd
{
    class IDisplay
    {
        public:
            IDisplay();
            virtual ~IDisplay();

            virtual void    draw(const wd::IScene &) = 0;
            virtual void    drawGameObject(const std::shared_ptr<wd::IGameObject> &) = 0;

        protected:
            virtual void    drawLayer(const std::vector<std::shared_ptr<wd::IGameObject>> &);
    };
}

#endif /* end of include guard: IDISPLAY_HPP_ */
