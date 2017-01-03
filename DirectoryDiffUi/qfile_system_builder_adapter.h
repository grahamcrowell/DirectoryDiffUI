#ifndef QFILE_SYSTEM_BUILDER_ADAPTER_H
#define QFILE_SYSTEM_BUILDER_ADAPTER_H

#include "stdafx.h"
#include "file_system_builder.h"

using namespace gc;
using namespace boost::filesystem;

class qfile_system_builder_adapter : public QObject
{
    Q_OBJECT
    QString _qroot_path_string;
    file_system_builder _file_system_builder;
public:
    explicit qfile_system_builder_adapter(QObject *parent = 0);

    void set_root_path(QString _qroot_path_string);
    void walk_directory();
    QList<QObject*> get_file_system();

signals:

public slots:
};

#endif // QFILE_SYSTEM_BUILDER_ADAPTER_H
