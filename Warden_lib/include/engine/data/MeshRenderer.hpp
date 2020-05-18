/*
** EPITECH PROJECT, 2019
** MeshRenderer.hpp
** File description:
** MeshRenderer Component Class Declaration
*/

#ifndef MESHRENDERER_HPP_
#define MESHRENDERER_HPP_

/// @file include/engine/data/MeshRenderer.hpp

#include "warden_lib.h"

///
/// MeshRenderer Class, contain path for Textual, 2d & 3d textures
///
class MeshRenderer : public AComponent
{
public:
    MeshRenderer(const QString & text, const QString &graph2d, const QString &graph3d);                 ///<Constructor, take 3 strings as parameter, as Text Texture path, 2D Texture path & 3D Texture path.
                                                                                                        ///<
    ~MeshRenderer();                                                                                    ///<Destructor
                                                                                                        ///<

    void update(event) final {}                                                                     ///<Update member Function
                                                                                                        ///<

    const QString & getText() const {return _text;}                                                     ///<Return the Text Texture Path
                                                                                                        ///<
    const QString & get2dGraph() const {return _graph2d;}                                               ///<Return the 2D Texture Path
                                                                                                        ///<
    const QString & get3dGraph() const {return _graph3d;}                                               ///<Return the 3D Texture Path
                                                                                                        ///<

private:
    const QString _text;
    const QString _graph2d;
    const QString _graph3d;

};

#endif /* end of include guard: MESHRENDERER_HPP_ */
