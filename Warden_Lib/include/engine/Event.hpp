/*
** EPITECH PROJECT, 2019
** Event.hpp
** File description:
** Event Enum Declaration
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

/// @file include/engine/Event.hpp

namespace wd
{
    enum event
    {
        UNKNOWN = -1,
        A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
        NUM0,NUM1,NUM2,NUM3,NUM4,NUM5,NUM6,NUM7,NUM8,NUM9,
        ESCAPE,SPACE,
        LCONTROL,LSHIFT,LALT,
        RCONTROL,RSHIFT,RALT,
        BACKSPACE,TAB,ENTER,PAGEUP,PAGEDOWN,
        LEFT,UP,RIGHT,DOWN,
        F1,F2,F3,F4,F5,F6,F7,F8, F9,F10,F11,F12,
        CLOSED_WINDOW
    };
}

#endif /* end of include guard: EVENT_HPP_ */
