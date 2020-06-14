#include "custombutton.h"
#include "inspector.h"


#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QFile>
#include <QJsonDocument>

Inspector::Inspector(QWidget *parent) : QVBoxLayout(parent)
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);

    _layout = new QVBoxLayout(parent);
    QLabel *label = new QLabel("Inspector");
    addWidget(label);
    QWidget* scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout(_layout);
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollAreaContent);
    addWidget(scrollArea);
}

void Inspector::setObj(const QJsonObject &json)
{
    _obj = new QJsonObject(json);
    if (json.contains("objectname") && json["objectname"].isString())
        addElement(new InspectorElement("GameObject Name", json["objectname"], _obj), _layout);
//        _name = json["name"].toString();
    if (json.contains("id") && json["id"].isDouble())
        addElement(new InspectorElement("id", json["id"], _obj), _layout);
//        _score = json["score"].toInt();
    if (json.contains("layer") && json["layer"].isDouble())
        addElement(new InspectorElement("layer", json["layer"], _obj), _layout);
//        _state = json["state"].toBool();
    if (json.contains("component") && json["component"].isArray()) {
        QJsonArray objArray = json["component"].toArray();
        _compo.clear();
        for (int compoIndex = 0; compoIndex < objArray.size(); ++compoIndex) {
            QLabel *label = new QLabel();
            label->setFrameStyle(QFrame::HLine | QFrame::Raised);
            _layout->addWidget(label);
            QJsonObject *compoObject = new QJsonObject(objArray[compoIndex].toObject());
            if (compoObject->contains("name")) {
                addElement(new InspectorElement("name", compoObject->value("name"), compoObject), _layout);
                _layout->addSpacing(20);
            }
            foreach(const QString& key, compoObject->keys()) {
                if (key != "name")
                    addElement(new InspectorElement(key, compoObject->value(key), compoObject), _layout);
            }
            _compo.append(compoObject);
        }
    }
}

QJsonObject *Inspector::saveObj()
{
    QJsonObject json;

    json["objectname"] = _obj->find("objectname").value();
    json["id"] = _obj->find("id").value();
    json["layer"] = _obj->find("layer").value();
    QJsonArray objectArray;
    for (auto const& x : _compo) {
        objectArray.append(*x);
    }
    json["component"] = objectArray;
    return new QJsonObject(json);
}

void Inspector::addElement(InspectorElement *element, QVBoxLayout *layout)
{
    layout->addLayout(element->layer());
    _elements.insert(element->key()->text(), element);
}

void Inspector::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
    }
}

void Inspector::clear()
{
    _elements.clear();
    clearLayout(_layout);
}
