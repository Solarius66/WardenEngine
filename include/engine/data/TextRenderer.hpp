/*
** EPITECH PROJECT, 2019
** TextRenderer.hpp
** File description:
** TextRenderer Component Class Declaration
*/

#ifndef TEXTRENDERER_HPP_
#define TEXTRENDERER_HPP_

/// @file include/engine/data/TextRenderer.hpp

#include "AComponent.hpp"

namespace wd
{
    ///
    /// TextRenderer Class, contain path for Textual, 2d & 3d textures
    ///
    class TextRenderer : public wd::AComponent
    {
    public:
        TextRenderer(const std::string & str = "");             ///<Constructor, take 1 string as parameter
                                                                ///<
        ~TextRenderer();                                        ///<Destructor
                                                                ///<

        void update(wd::event) final {}                         ///<Update member Function
                                                                ///<

        const std::string & getText() const {return _str;}      ///<Return the Text Texture Path
                                                                ///<
        void setText(const std::string &);                      ///<Set _str value
                                                                ///<
        void addText(const std::string &);                      ///<Set _str value
                                                                ///<
        void removeText(int);                                   ///<Remove number of characters at the end of _str, equal to value taken as parameter
                                                                ///<

    private:
        std::string _str;

    };
}

#endif /* end of include guard: TEXTRENDERER_HPP_ */
