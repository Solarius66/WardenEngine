#include "inspectorelement.h"

#include <QJsonObject>
#include <QDebug>

InspectorElement::InspectorElement(const QString &key, const QJsonValue &value, QJsonObject *obj, QWidget *parent) : QWidget(parent)
{
    _layer = new QHBoxLayout();
    _key = new QLabel(key);
    _layer->addWidget(_key);
    _obj = obj;
    if (value.isString()) _value = new QLineEdit(value.toString());
    if (value.isDouble()) _value = new QLineEdit(QString::number(value.toDouble()));
    _layer->addWidget(_value);
    connect(_value, SIGNAL(textEdited(QString)), this, SLOT(myTextChanged(QString)));
}

QLabel *InspectorElement::key() const
{
    return _key;
}

void InspectorElement::setKey(QLabel *key)
{
    _key = key;
}

QLineEdit *InspectorElement::value() const
{
    return _value;
}

void InspectorElement::setValue(QLineEdit *value)
{
    _value = value;
}

QHBoxLayout *InspectorElement::layer() const
{
    return _layer;
}

void InspectorElement::setLayer(QHBoxLayout *layer)
{
    _layer = layer;
}

QJsonObject *InspectorElement::obj() const
{
    return _obj;
}

void InspectorElement::myTextChanged(QString str)
{
    if (_obj->value(_key->text()).isString()) {
        _obj->find(_key->text()).value() = str;
    }
    if (_obj->value(_key->text()).isDouble()) {
        _obj->find(_key->text()).value() = str.toInt();
    }
}
