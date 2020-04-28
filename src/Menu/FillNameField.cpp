/*
** EPITECH PROJECT, 2019
** FillNameField.cpp
** File description:
** FillNameField Class Implementation
*/

#include <memory>
#include <iostream>

#include "FillNameField.hpp"
#include "TextRenderer.hpp"

wd::FillNameField::FillNameField(const std::shared_ptr<wd::AGameObject> &obj) : AComponent("FillNameField")
{
    _obj = obj;
}

void wd::FillNameField::update(wd::event event)
{
    if (event == wd::A) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("A");}
    if (event == wd::B) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("B");}
    if (event == wd::C) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("C");}
    if (event == wd::D) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("D");}
    if (event == wd::E) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("E");}
    if (event == wd::F) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("F");}
    if (event == wd::G) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("G");}
    if (event == wd::H) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("H");}
    if (event == wd::I) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("I");}
    if (event == wd::J) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("J");}
    if (event == wd::K) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("K");}
    if (event == wd::L) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("L");}
    if (event == wd::M) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("M");}
    if (event == wd::N) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("N");}
    if (event == wd::O) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("O");}
    if (event == wd::P) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("P");}
    if (event == wd::Q) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("Q");}
    if (event == wd::R) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("R");}
    if (event == wd::S) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("S");}
    if (event == wd::T) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("T");}
    if (event == wd::U) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("U");}
    if (event == wd::V) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("V");}
    if (event == wd::W) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("W");}
    if (event == wd::X) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("X");}
    if (event == wd::Y) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("Y");}
    if (event == wd::Z) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("Z");}
    if (event == wd::NUM0) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("0");}
    if (event == wd::NUM1) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("1");}
    if (event == wd::NUM2) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("2");}
    if (event == wd::NUM3) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("3");}
    if (event == wd::NUM4) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("4");}
    if (event == wd::NUM5) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("5");}
    if (event == wd::NUM6) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("6");}
    if (event == wd::NUM7) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("7");}
    if (event == wd::NUM8) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("8");}
    if (event == wd::NUM9) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText("9");}
    if (event == wd::SPACE) {_obj->getComponent<wd::TextRenderer>("TextRenderer").addText(" ");}
    if (event == wd::BACKSPACE) {_obj->getComponent<wd::TextRenderer>("TextRenderer").removeText(1);}
}
