/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2011 SCHUTZ Sacha
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "qjsonmodel.h"
#include <QFile>
#include <QDebug>
#include <QFont>


QJsonTreeItem::QJsonTreeItem(QJsonTreeItem *parent)
{
    mParent = parent;
}

QJsonTreeItem::~QJsonTreeItem()
{
    qDeleteAll(mChilds);
}

void QJsonTreeItem::appendChild(QJsonTreeItem *item)
{
    mChilds.append(item);
}

QJsonTreeItem *QJsonTreeItem::child(int row)
{
    return mChilds.value(row);
}

QJsonTreeItem *QJsonTreeItem::parent()
{
    return mParent;
}

int QJsonTreeItem::childCount() const
{
    return mChilds.count();
}

int QJsonTreeItem::row() const
{
    if (mParent)
        return mParent->mChilds.indexOf(const_cast<QJsonTreeItem*>(this));

    return 0;
}

void QJsonTreeItem::setKey(const QString &key)
{
    mKey = key;
}

void QJsonTreeItem::setType(const QJsonValue::Type &type)
{
    mType = type;
}

QString QJsonTreeItem::key() const
{
    return mKey;
}

QJsonValue::Type QJsonTreeItem::type() const
{
    return mType;
}

QJsonTreeItem* QJsonTreeItem::load(const QJsonValue& value, QJsonTreeItem* parent)
{
    QJsonTreeItem * rootItem = new QJsonTreeItem(parent);
    rootItem->setKey("root");

    if ( value.isObject())
    {
        rootItem->setObject(new QJsonObject(value.toObject()));
        for (QString key : value.toObject().keys()){
            if (key == "object") {
                QJsonValue v = value.toObject().value(key);
                QJsonTreeItem * child = load(v,rootItem);
                child->setKey(value.toObject().value("name").toString());
                child->setType(v.type());
                rootItem->appendChild(child);
            }
        }
    }
    else if ( value.isArray())
    {
        for (QJsonValue v : value.toArray()){
            QJsonTreeItem * child = load(v,rootItem);
            child->setKey(v.toObject().value("objectname").toString());
            child->setType(v.type());
            rootItem->appendChild(child);
        }
    }
    else
    {
        rootItem->setType(value.type());
    }
    return rootItem;
}

QJsonObject *QJsonTreeItem::object() const
{
    return _object;
}

void QJsonTreeItem::setObject(QJsonObject *object)
{
    _object = object;
}

QList<QJsonTreeItem *> QJsonTreeItem::childs() const
{
    return mChilds;
}

void QJsonTreeItem::setChilds(const QList<QJsonTreeItem *> &childs)
{
    mChilds = childs;
}

//=========================================================================

QJsonModel::QJsonModel(QObject *parent)
    : QAbstractItemModel(parent)
    , mRootItem{new QJsonTreeItem}
{
    mHeaders.append("TreeView");
}

QJsonModel::QJsonModel(const QString& fileName, QObject *parent)
    : QAbstractItemModel(parent)
    , mRootItem{new QJsonTreeItem}
{
    mHeaders.append("TreeView");
    load(fileName);
}

QJsonModel::QJsonModel(QIODevice * device, QObject *parent)
    : QAbstractItemModel(parent)
    , mRootItem{new QJsonTreeItem}
{
    mHeaders.append("TreeView");
    load(device);
}

QJsonModel::QJsonModel(const QByteArray& json, QObject *parent)
    : QAbstractItemModel(parent)
    , mRootItem{new QJsonTreeItem}
{
    mHeaders.append("TreeView");
    loadJson(json);
}

QJsonModel::~QJsonModel()
{
    delete mRootItem;
}

bool QJsonModel::load(const QString &fileName)
{
    QFile file(fileName);
    bool success = false;
    if (file.open(QIODevice::ReadOnly)) {
        success = load(&file);
        file.close();
    }
    else success = false;

    return success;
}

bool QJsonModel::load(QIODevice *device)
{
    return loadJson(device->readAll());
}

bool QJsonModel::loadJson(const QByteArray &json)
{
    auto const& jdoc = QJsonDocument::fromJson(json);

    if (!jdoc.isNull())
    {
        beginResetModel();
        delete mRootItem;
        if (jdoc.isArray()) {
            mRootItem = QJsonTreeItem::load(QJsonValue(jdoc.array()));
            mRootItem->setType(QJsonValue::Array);

        } else {
            mRootItem = QJsonTreeItem::load(QJsonValue(jdoc.object()));
            mRootItem->setType(QJsonValue::Object);
        }
        endResetModel();
        return true;
    }

    qDebug()<<Q_FUNC_INFO<<"cannot load json";
    return false;
}


QVariant QJsonModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
        return QVariant();


    QJsonTreeItem *item = static_cast<QJsonTreeItem*>(index.internalPointer());


    if (role == Qt::DisplayRole) {
        return QString("%1").arg(item->key());
    }
    return QVariant();
}

QVariant QJsonModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {

        return mHeaders.value(section);
    }
    else
        return QVariant();
}

QModelIndex QJsonModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    QJsonTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = mRootItem;
    else
        parentItem = static_cast<QJsonTreeItem*>(parent.internalPointer());

    QJsonTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex QJsonModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    QJsonTreeItem *childItem = static_cast<QJsonTreeItem*>(index.internalPointer());
    QJsonTreeItem *parentItem = childItem->parent();

    if (parentItem == mRootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int QJsonModel::rowCount(const QModelIndex &parent) const
{
    QJsonTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = mRootItem;
    else
        parentItem = static_cast<QJsonTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int QJsonModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 1;
}

Qt::ItemFlags QJsonModel::flags(const QModelIndex &index) const
{
    int col   = index.column();
    auto item = static_cast<QJsonTreeItem*>(index.internalPointer());

    auto isArray = QJsonValue::Array == item->type();
    auto isObject = QJsonValue::Object == item->type();

    if ((col == 1) && !(isArray || isObject)) {
        return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
    } else {
        return QAbstractItemModel::flags(index);
    }
}

QJsonDocument QJsonModel::json() const
{

    auto v = genJson(mRootItem);
    QJsonDocument doc;

    if (v.isObject()) {
        doc = QJsonDocument(v.toObject());
    } else {
        doc = QJsonDocument(v.toArray());
    }

    return doc;
}

QJsonValue  QJsonModel::genJson(QJsonTreeItem * item) const
{
    auto type   = item->type();
    int  nchild = item->childCount();

    if (QJsonValue::Object == type) {
        QJsonObject jo;
        for (int i = 0; i < nchild; ++i) {
            auto ch = item->child(i);
            auto key = ch->key();
            jo.insert(key, genJson(ch));
        }
        return  jo;
    } else if (QJsonValue::Array == type) {
        QJsonArray arr;
        for (int i = 0; i < nchild; ++i) {
            auto ch = item->child(i);
            arr.append(genJson(ch));
        }
        return arr;
    }
    return QJsonValue();
}

QJsonTreeItem *QJsonModel::rootItem() const
{
    return mRootItem;
}
