#include "custombutton.h"

CustomButton::CustomButton(QString text, QWidget *parent) : QPushButton(parent)
{
    setText(text);
}
