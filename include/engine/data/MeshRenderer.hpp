/*
** EPITECH PROJECT, 2019
** MeshRenderer.hpp
** File description:
** MeshRenderer Component Class Declaration
*/

#ifndef MESHRENDERER_HPP_
#define MESHRENDERER_HPP_

/// @file include/engine/data/MeshRenderer.hpp

#include "AComponent.hpp"

namespace wd
{
    ///
    /// MeshRenderer Class, contain path for Textual, 2d & 3d textures
    ///
    class MeshRenderer : public wd::AComponent
    {
    public:
        MeshRenderer(const std::string & text, const std::string &graph2d, const std::string &graph3d);     ///<Constructor, take 3 strings as parameter, as Text Texture path, 2D Texture path & 3D Texture path.
                                                                                                            ///<
    ~MeshRenderer();                                                                                        ///<Destructor
                                                                                                            ///<

        void update(wd::event) final {}                                                                     ///<Update member Function
                                                                                                            ///<

        const std::string & getText() const {return _text;}                                                 ///<Return the Text Texture Path
                                                                                                            ///<
        const std::string & get2dGraph() const {return _graph2d;}                                           ///<Return the 2D Texture Path
                                                                                                            ///<
        const std::string & get3dGraph() const {return _graph3d;}                                           ///<Return the 3D Texture Path
                                                                                                            ///<

    private:
        const std::string _text;
        const std::string _graph2d;
        const std::string _graph3d;

    };
}

#endif /* end of include guard: MESHRENDERER_HPP_ */
