#include "qjsonmodel.h"
#include "treeviewlayout.h"

#include <QFile>
#include <QDebug>

TreeViewLayout::TreeViewLayout(const QString &path, QWidget *parent) : QVBoxLayout(parent)
{
    setAlignment(Qt::AlignTop | Qt::AlignLeft);

    QFile loadFile(path);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    _obj = loadDoc.object();
    _model = new QJsonModel(path, this);
    _view = new QTreeView;
    _view->setModel(_model);
    _view->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    addWidget(_view, 1);
}

QTreeView *TreeViewLayout::view() const
{
    return _view;
}

void TreeViewLayout::setView(QTreeView *view)
{
    _view = view;
}

QJsonModel *TreeViewLayout::model() const
{
    return _model;
}

void TreeViewLayout::setModel(QJsonModel *model)
{
    _model = model;
}

void TreeViewLayout::updateJson()
{
    QJsonObject tmp;

    tmp["name"] = _model->rootItem()->object()->find("name").value();
    tmp["score"] = _model->rootItem()->object()->find("score").value();
    tmp["state"] = _model->rootItem()->object()->find("state").value();
    QJsonArray objectArray;
    for (auto const& x : _model->rootItem()->childs()) {
        if (x->object())
            objectArray.append(QJsonValue(*x->object()));
    }
    tmp["object"] = objectArray;
    _obj = tmp;
}

