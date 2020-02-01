/*
** EPITECH PROJECT, 2020
** WardenEngine
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "ICore.hpp"

#pragma pack(push, 1)

namespace wd {
    class Core : public wd::ICore {
        public:
            Core();
            ~Core();

            void Update(wd::IScene activeScene);
            void Stop();

        private:
            sf::Event _event;
};
}

#pragma pack(pop)

#endif /* !CORE_HPP_ */
