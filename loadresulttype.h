#ifndef LOADRESULTTYPE_H
#define LOADRESULTTYPE_H

#include <QObject>
#include <QDebug>

class LoadResultType : public QObject
{
    Q_OBJECT
public:
    LoadResultType() : QObject() {}
    enum ResultType
    {
        SUCCESS,
        ERROR
    };
    Q_ENUMS(ResultType)

signals:

public slots:
};

#endif // LOADRESULTTYPE_H