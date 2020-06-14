#ifndef TREEVIEWLAYOUT_H
#define TREEVIEWLAYOUT_H

#include "custombutton.h"
#include "qjsonmodel.h"

#include <QJsonObject>
#include <QTreeView>
#include <QVBoxLayout>

class TreeViewLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    TreeViewLayout(const QString &path, QWidget *parent);
    QJsonObject obj() const {return _obj;}
    void setObj(const QJsonObject &obj) {_obj = obj;}

    QTreeView *view() const;
    void setView(QTreeView *view);
    QJsonModel *model() const;
    void setModel(QJsonModel *model);
    void updateJson();

private:
    QJsonObject _obj;
    QJsonModel *_model;
    QTreeView *_view;
};

#endif // TREEVIEWLAYOUT_H
