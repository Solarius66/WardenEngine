/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main Function of Arcade Project
*/

#include <iostream>
#include <ctime>

#include "GameEngine.hpp"
#include "EngineError.hpp"

int main(void)
{
    try {
        std::unique_ptr<wd::GameEngine> engine = std::make_unique<wd::GameEngine>();
        engine->loop();
    }
    catch (const wd::error::EngineError &e) {
        std::cerr << e.getType() << " : " << e.getMsg() << std::endl;
        return (84);
    }
    return 0;
}
