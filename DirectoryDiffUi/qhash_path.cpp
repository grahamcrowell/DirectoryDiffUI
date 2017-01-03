#include "qhash_path.h"

qhash_path::qhash_path(QObject *parent) : QObject(parent)
{

}

qhash_path::qhash_path(const QString &generic_string, QObject *parent)
{
    this->generic_string = generic_string;
}

QString qhash_path::get_generic_string()
{
    return generic_string;
}

void qhash_path::set_generic_string(QString generic_string)
{
    this->generic_string = generic_string;
}
