#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include <QPushButton>
#include <QWidget>

#include "warden_lib.h"

class SaveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SaveButton(QWidget *parent = nullptr);

};

#endif // SAVEBUTTON_H
