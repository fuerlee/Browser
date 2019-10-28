#ifndef FSUTIL_H
#define FSUTIL_H

#include <QDir>
#include <QFileInfo>
#include <QDebug>

class FsUtil {
public:
    static QString DRAKO_DIR_NAME;
    static QDir DRAKO_DIR;

    static void createAndSetHomeFolder();
    static QDir createSiteFolderIfNeeded(QString siteUrl);
    static QFileInfo getMainQmlFile(QString siteUrl);
};

#endif // FSUTIL_H