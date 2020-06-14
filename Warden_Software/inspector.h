#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <QGroupBox>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>

#include "inspectorelement.h"

class Inspector : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit Inspector(QWidget *parent = nullptr);

    void setObj(const QJsonObject &value);
    QJsonObject *saveObj();

    void clearLayout(QLayout *layout);
    void clear();

    void addElement(InspectorElement *element, QVBoxLayout *layout);
signals:

private:
    QVBoxLayout *_layout;
    QMap<QString, InspectorElement *> _elements;
    QJsonObject *_obj;
    QVector<QJsonObject *> _compo;
};

#endif // INSPECTOR_H
