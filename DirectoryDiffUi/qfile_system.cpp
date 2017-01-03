#include "qfile_system.h"
#include <iostream>
qfile_system::qfile_system(QObject *parent) : QObject(parent)
{
    std::cout << "asdfalkj";

    qhash_path* _qhash_path = new qhash_path();
//    QVariant *qvar = new QVariant("sdf");
//    _qhash_path->setProperty("generic_string", qvar);
    _qhash_path->set_generic_string(QString("sdf "));
//    _qhash_path->generic_string = QString("sdf ");
    _hash_paths.append(_qhash_path);
}
