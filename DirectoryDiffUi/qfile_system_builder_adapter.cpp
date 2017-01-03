#include "qfile_system_builder_adapter.h"
#include "qhash_path.h"

qfile_system_builder_adapter::qfile_system_builder_adapter(QObject *parent) : QObject(parent)
{

}

void qfile_system_builder_adapter::set_root_path(QString _qroot_path_string)
{
    this->_qroot_path_string = _qroot_path_string;
    this->_file_system_builder.set_root_path(path(_qroot_path_string.toStdString()));
}

void qfile_system_builder_adapter::walk_directory()
{
    _file_system_builder.walk_directory();

}

QList<QObject *> qfile_system_builder_adapter::get_file_system()
{
    QList<QObject *> _qpath_list;
    for_each(_file_system_builder.hash_paths()->begin(),_file_system_builder.hash_paths()->end(),[&](auto& hp){
        //std::cout << hp.generic_string() << std::endl;
        _qpath_list.append(new qhash_path(QString::fromStdString(hp.generic_string())));

    });
    return _qpath_list;
}
