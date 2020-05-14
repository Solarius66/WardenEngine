#include "mainwindow.h"

#include <QApplication>
#include "Warden.hpp"
#include <memory>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    wd::IScene *scene = new wd::AScene("Test");
    std::shared_ptr<wd::AGameObject> obj= std::make_shared<wd::AGameObject>("obj", wd::PLAYER, wd::FOREGROUND);
    obj->addComponent<wd::MeshRenderer>("MeshRenderer", "./texture", "./texture", "./texture");
    scene->addObject(obj);
    qDebug(scene->getFromName("obj")->getComponent<wd::MeshRenderer>("MeshRenderer").getText().c_str());
    w.show();
    return a.exec();
}
