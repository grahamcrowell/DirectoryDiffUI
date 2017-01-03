#ifndef QFILE_SYSTEM_H
#define QFILE_SYSTEM_H

#include <QObject>
#include <QVariant>

#include "qhash_path.h"
#include "gc_file_system.h"

class qfile_system : public QObject
{
    Q_OBJECT

public:
    QList<QObject*> _hash_paths;
    explicit qfile_system(QObject *parent = 0);

signals:

public slots:
};

#endif // QFILE_SYSTEM_H
