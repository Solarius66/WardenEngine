#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QWidget>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QString name, QWidget *parent = nullptr);

signals:

};

#endif // CUSTOMBUTTON_H
