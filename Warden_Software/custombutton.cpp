#include "custombutton.h"

CustomButton::CustomButton(QString name, QWidget *parent) : QPushButton(parent)
{
    setText(name);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}
