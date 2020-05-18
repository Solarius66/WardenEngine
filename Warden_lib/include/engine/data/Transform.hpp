/*
** EPITECH PROJECT, 2019
** Transform.hpp
** File description:
** Transform Component Class Declaration
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

/// @file include/engine/data/Transform.hpp

#include "warden_lib.h"

///
/// Transform Class, contain position, size, scale and rotation of a GameObject
///
class Transform : public AComponent
{
public:
    Transform(Vector3float);                    ///<Constructor using Vector3float as parameter to set position value
                                                    ///<
    Transform(float x = 0, float y = 0, float z = 0);///<Constructor using Vector3float as parameter to set position value
                                                    ///<
    ~Transform();                                   ///<Destructor
                                                    ///<

    void translate(Vector3float);               ///<Add parameters values to _position attribute
                                                    ///<
    void translate(float x = 0, float y = 0, float z = 0);///<Add parameters values to _position attribute
                                                    ///<
    void rotate(Vector3float);                    ///<Add parameters values to _rotation attribute
                                                    ///<
    void rotate(float x = 0, float y = 0, float z = 0);   ///<Add parameters values to _rotation attribute
                                                    ///<
    void rescale(Vector3float);                   ///<Add parameters values to _scale attribute
                                                    ///<
    void rescale(float x = 0, float y = 0, float z = 0);  ///<Add parameters values to _scale attribute
                                                    ///<
    void resize(Vector3float);                    ///<Add parameters values to _size attribute
                                                    ///<
    void resize(float x = 0, float y = 0, float z = 0);   ///<Add parameters values to _size attribute
                                                    ///<
    void setPosition(Vector3float);               ///<Reset Position values to parameter Values
                                                    ///<
    void setPosition(float x = 0, float y = 0, float z = 0);  ///<Reset Position values to parameter Values
                                                        ///<
    void setRotation(Vector3float);                   ///<Reset Rotation values to parameter Values
                                                        ///<
    void setRotation(float x = 0, float y = 0, float z = 0);  ///<Reset Rotation values to parameter Values
                                                        ///<
    void setScale(Vector3float);                      ///<Reset Scale values to parameter Values
                                                        ///<
    void setScale(float x = 0, float y = 0, float z = 0);     ///<Reset Scale values to parameter Values
                                                        ///<
    void setSize(Vector3float);                       ///<Reset Position values to parameter Values
                                                        ///<
    void setSize(float x = 0, float y = 0, float z = 0);      ///<Reset Position values to parameter Values
                                                        ///<

    Vector3float getPosition() const {return _position;}  ///<Return _position
                                                            ///<
    Vector3float getRotation() const {return _rotation;}  ///<Return _position
                                                            ///<
    Vector3float getScale() const {return _scale;}        ///<Return _position
                                                            ///<
    Vector3float getSize() const {return _size;}          ///<Return _position
                                                            ///<

    void update(event) final;   ///<Update member function
                                    ///<

private:
    Vector3float _position; ///<Values x, y, z corresponding to the position of the GameObject
                                ///<
    Vector3float _rotation; ///<Values x, y, z corresponding to the rotation of the GameObject
                                ///<
    Vector3float _scale;    ///<Values x, y, z corresponding to the scale of the GameObject
                                ///<
    Vector3float _size;     ///<Values x, y, z corresponding to the size of the GameObject
                                ///<
};

#endif /* end of include guard: TRANSFORM_HPP_ */
