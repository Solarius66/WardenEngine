/*
** EPITECH PROJECT, 2019
** TextRenderer.hpp
** File description:
** TextRenderer Component Class Declaration
*/

#ifndef TEXTRENDERER_HPP_
#define TEXTRENDERER_HPP_

/// @file include/engine/data/TextRenderer.hpp

#include <QString>
#include <QJsonObject>

#include "include/engine/data/AComponent.hpp"

///
/// TextRenderer Class, contain path for Textual, 2d & 3d textures
///
class TextRenderer : public AComponent
{
public:
    ///<Constructor, take 1 string as parameter
    TextRenderer(const QString & str = ""); ///<

    ///<Destructor
    ~TextRenderer(); ///<

    ///<Update member Function
    void update(event) final {} ///<

    ///<Return the Text Texture Path
    const QString & getText() const {return _str;} ///<

    ///<Set _str value
    void setText(const QString &); ///<

    ///<Set _str value
    void addText(const QString &); ///<

    ///<Remove number of characters at the end of _str, equal to value taken as parameter
    void removeText(int); ///<

    ///<Load a TextRenderer from a .json object
    void read(const QJsonObject &json); ///<

    ///<Save a TextRenderer in a .json object
    void write(QJsonObject &json) const; ///<

private:
    QString _str;

};

#endif /* end of include guard: TEXTRENDERER_HPP_ */
