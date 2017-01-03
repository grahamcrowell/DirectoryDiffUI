#include <QGuiApplication>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "qfile_system.h"
#include "qfile_system_builder_adapter.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView file_system_view;
    file_system_view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctxt = file_system_view.rootContext();



    QList<QObject*> dataList;
    dataList.append(new qhash_path("Item 1"));
 //ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));


    QList<QObject*> hash_path_list;
    qfile_system_builder_adapter _qfile_system_builder_adapter;
    _qfile_system_builder_adapter.set_root_path(QString::fromStdString(std::string(R"(C:\Users\user\Desktop\sync_test\testDst)")));
    _qfile_system_builder_adapter.walk_directory();
    hash_path_list = _qfile_system_builder_adapter.get_file_system();
 ctxt->setContextProperty("myModel", QVariant::fromValue(hash_path_list));



    file_system_view.setSource(QUrl("qrc:main.qml"));
    file_system_view.show();

    return app.exec();
}
