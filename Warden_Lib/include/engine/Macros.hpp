/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Declaration of all macros for the SceneManager handling
*/

#ifndef MACROS_HPP
#define MACROS_HPP

/// @file include/engine/Macros.hpp

namespace wd {
    ///
    /// Definition of the macros for the different layers (you can add up to 7 more, between FOREGROUND 1 and HUD 9)
    ///
    const int BACKGROUND    = 0;   ///<Background layer macro
    ///<

    ///
    ///Add your layers here
    ///

    const int FOREGROUND    = 8;   ///<Foreground layer macro
    ///<
    const int HUD           = 9;   ///<HUD layer macro
    ///<

    ///
    /// Definition of the macros for the different ID of GameObject (you can add more ID after the SYSTEM one)
    ///
    const int NOTHING       = 0;   ///<Nothing ID macro
    ///<
    const int PLAYER        = 1;   ///<Player ID macro
    ///<
    const int ENEMY         = 2;   ///<Enemy ID macro
    ///<
    const int ITEM          = 3;   ///<Item ID macro
    ///<
    const int WALL          = 4;  ///<Wall ID macro
    ///<
    const int SYSTEM        = 5;  ///<System ID macro
    ///<

    ///
    ///Add your IDs here
    ///

    ///
    ///Definition of Direction Macros
    ///
    const int DIR_UP        = 0;    ///<Up Direction Macro
    ///<
    const int DIR_RIGHT     = 1;    ///<Right Direction Macro
    ///<
    const int DIR_DOWN      = 2;    ///<Down Direction Macro
    ///<
    const int DIR_LEFT      = 3;    ///<Left Direction Macro
    ///<
}

#endif /* !MACROS_HPP */
