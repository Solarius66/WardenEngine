/*
** EPITECH PROJECT, 2019
** FillNameField.hpp
** File description:
** FillNameField Class Declaration
*/

#ifndef FILLNAMEFIELD_HPP_
#define FILLNAMEFIELD_HPP_

#include "AComponent.hpp"
#include "Event.hpp"
#include "AGameObject.hpp"

namespace wd
{
    class FillNameField : public AComponent
    {
    public:
        FillNameField(const std::shared_ptr<wd::AGameObject> &obj);
        ~FillNameField() = default;

        void update(wd::event);

    private:
        std::shared_ptr<wd::AGameObject>    _obj;
    };
}

#endif /* end of include guard: FILLNAMEFIELD_HPP_ */
