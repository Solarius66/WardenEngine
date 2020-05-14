#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QWidget>
#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QString text, QWidget *parent = nullptr);


signals:

};

#endif // CUSTOMBUTTON_H
