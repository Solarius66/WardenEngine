/*
** EPITECH PROJECT, 2019
** TextRenderer.hpp
** File description:
** TextRenderer Component Class Declaration
*/

#ifndef TEXTRENDERER_HPP_
#define TEXTRENDERER_HPP_

/// @file include/engine/data/TextRenderer.hpp

#include "warden_lib.h"

///
/// TextRenderer Class, contain path for Textual, 2d & 3d textures
///
class TextRenderer : public AComponent
{
public:
    TextRenderer(const QString & str = "");             ///<Constructor, take 1 string as parameter
                                                            ///<
    ~TextRenderer();                                        ///<Destructor
                                                            ///<

    void update(event) final {}                         ///<Update member Function
                                                            ///<

    const QString & getText() const {return _str;}      ///<Return the Text Texture Path
                                                            ///<
    void setText(const QString &);                      ///<Set _str value
                                                            ///<
    void addText(const QString &);                      ///<Set _str value
                                                            ///<
    void removeText(int);                                   ///<Remove number of characters at the end of _str, equal to value taken as parameter
                                                            ///<

private:
    QString _str;

};

#endif /* end of include guard: TEXTRENDERER_HPP_ */
