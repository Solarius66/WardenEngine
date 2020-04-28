/*
** EPITECH PROJECT, 2019
** Transform.hpp
** File description:
** Transform Component Class Declaration
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

/// @file include/engine/data/Transform.hpp

#include "AComponent.hpp"
#include "Vector3float.hpp"

namespace wd
{
    ///
    /// Transform Class, contain position, size, scale and rotation of a GameObject
    ///
    class Transform : public wd::AComponent
    {
    public:
        Transform(wd::Vector3float);                      ///<Constructor using Vector3float as parameter to set position value
                                                        ///<
        Transform(float x = 0, float y = 0, float z = 0);     ///<Constructor using Vector3float as parameter to set position value
                                                        ///<
        ~Transform();                                   ///<Destructor
                                                        ///<

        void translate(wd::Vector3float);                 ///<Add parameters values to _position attribute
                                                        ///<
        void translate(float x = 0, float y = 0, float z = 0);///<Add parameters values to _position attribute
                                                        ///<
        void rotate(wd::Vector3float);                    ///<Add parameters values to _rotation attribute
                                                        ///<
        void rotate(float x = 0, float y = 0, float z = 0);   ///<Add parameters values to _rotation attribute
                                                        ///<
        void rescale(wd::Vector3float);                   ///<Add parameters values to _scale attribute
                                                        ///<
        void rescale(float x = 0, float y = 0, float z = 0);  ///<Add parameters values to _scale attribute
                                                        ///<
        void resize(wd::Vector3float);                    ///<Add parameters values to _size attribute
                                                        ///<
        void resize(float x = 0, float y = 0, float z = 0);   ///<Add parameters values to _size attribute
                                                        ///<
        void setPosition(wd::Vector3float);               ///<Reset Position values to parameter Values
                                                        ///<
        void setPosition(float x = 0, float y = 0, float z = 0);  ///<Reset Position values to parameter Values
                                                            ///<
        void setRotation(wd::Vector3float);                   ///<Reset Rotation values to parameter Values
                                                            ///<
        void setRotation(float x = 0, float y = 0, float z = 0);  ///<Reset Rotation values to parameter Values
                                                            ///<
        void setScale(wd::Vector3float);                      ///<Reset Scale values to parameter Values
                                                            ///<
        void setScale(float x = 0, float y = 0, float z = 0);     ///<Reset Scale values to parameter Values
                                                            ///<
        void setSize(wd::Vector3float);                       ///<Reset Position values to parameter Values
                                                            ///<
        void setSize(float x = 0, float y = 0, float z = 0);      ///<Reset Position values to parameter Values
                                                            ///<

        wd::Vector3float getPosition() const {return _position;}  ///<Return _position
                                                                ///<
        wd::Vector3float getRotation() const {return _rotation;}  ///<Return _position
                                                                ///<
        wd::Vector3float getScale() const {return _scale;}        ///<Return _position
                                                                ///<
        wd::Vector3float getSize() const {return _size;}          ///<Return _position
                                                                ///<

        void update(wd::event) final;   ///<Update member function
                                        ///<

    private:
        wd::Vector3float _position;   ///<Values x, y, z corresponding to the position of the GameObject
                                    ///<
        wd::Vector3float _rotation;   ///<Values x, y, z corresponding to the rotation of the GameObject
                                    ///<
        wd::Vector3float _scale;      ///<Values x, y, z corresponding to the scale of the GameObject
                                    ///<
        wd::Vector3float _size;       ///<Values x, y, z corresponding to the size of the GameObject
                                    ///<
    };
}

#endif /* end of include guard: TRANSFORM_HPP_ */
