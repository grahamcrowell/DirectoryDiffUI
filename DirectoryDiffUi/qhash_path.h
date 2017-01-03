#ifndef QHASH_PATH_H
#define QHASH_PATH_H

#include <QObject>

class qhash_path : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString generic_string READ get_generic_string WRITE set_generic_string)



public:
    QString generic_string;
    explicit qhash_path(QObject *parent = 0);
    explicit qhash_path(const QString &generic_string, QObject *parent = 0);

    QString get_generic_string();
    void set_generic_string(QString generic_string);

signals:

public slots:
};

#endif // QHASH_PATH_H
