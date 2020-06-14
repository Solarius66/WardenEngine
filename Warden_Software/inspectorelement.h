#ifndef INSPECTORELEMENT_H
#define INSPECTORELEMENT_H

#include "mainwindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class InspectorElement : public QWidget
{
    Q_OBJECT
public:
    explicit InspectorElement(const QString &key, const QJsonValue &value, QJsonObject *obj, QWidget *parent = nullptr);

    QLabel *key() const;
    void setKey(QLabel *key);

    QLineEdit *value() const;
    void setValue(QLineEdit *value);

    QHBoxLayout *layer() const;
    void setLayer(QHBoxLayout *layer);

    QJsonObject *obj() const;

public slots:
    void myTextChanged(QString str);

signals:

private:
    QLabel *_key;
    QLineEdit *_value;
    QHBoxLayout *_layer;
    QJsonObject *_obj;
};

#endif // INSPECTORELEMENT_H
