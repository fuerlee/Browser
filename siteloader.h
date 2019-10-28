#ifndef SITELOADER_H
#define SITELOADER_H

#include <QObject>
#include <QDebug>

class SiteLoader : public QObject
{
    Q_OBJECT
public:
    explicit SiteLoader(QObject *parent = nullptr);
    Q_INVOKABLE int loadSite(QString siteUrl);
    Q_INVOKABLE QString loadProperties(QString siteUrl);
    Q_INVOKABLE QString getMainQmlPath(QString siteUrl);

signals:

public slots:
};

#endif // SITELOADER_H