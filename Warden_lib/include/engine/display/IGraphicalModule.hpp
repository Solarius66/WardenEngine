/*
** EPITECH PROJECT, 2019
** IGameModule.hpp
** File description:
** GameModule Interface Declaration
*/

#ifndef IGRAPHICALMODULE_HPP_
#define IGRAPHICALMODULE_HPP_

/// @file include/engine/display/IGraphicalModule.hpp

#include "include/engine/data/AGameObject.hpp"

class IGraphicalModule
{
public:
    IGraphicalModule() = default;           ///<Constructor
                                            ///<
    virtual ~IGraphicalModule() = default;  ///<Destructor
                                            ///<

    virtual const QString & getTitle() const = 0;                               ///<Return the Name of the Module
                                                                                    ///<
    virtual void                draw(const QSharedPointer<AGameObject> &) = 0; ///<Draw the gameObject in the Window
                                                                                    ///<
    virtual void                manageEvent(QQueue<event> &) = 0;             ///<Add Event in the queue if needed
                                                                                    ///<
};

#endif /* end of include guard: IGRAPHICALMODULE_HPP_ */
