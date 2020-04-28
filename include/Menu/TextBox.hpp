/*
** EPITECH PROJECT, 2019
** TextBox.hpp
** File description:
** TextBox Class Declaration
*/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_

#include "AGameObject.hpp"

namespace wd
{
    class TextBox : public wd::AGameObject
    {
    public:
        TextBox(const std::string &name, int id, int layer, const std::string &str = "");
        TextBox(wd::TextBox &);
        ~TextBox() = default;
    };
}

#endif /* end of include guard: TEXTBOX_HPP_ */
