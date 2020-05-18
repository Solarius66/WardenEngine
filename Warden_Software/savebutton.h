#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include <QPushButton>
#include <QWidget>

#include "Warden.hpp"

class SaveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SaveButton(QWidget *parent = nullptr);
    void 	clicked(std::shared_ptr<wd::IScene> scene, bool checked = false);
};

#endif // SAVEBUTTON_H
