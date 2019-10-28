#include "fsutil.h"

QString FsUtil::DRAKO_DIR_NAME = ".drako";
QDir FsUtil::DRAKO_DIR;

void FsUtil::createAndSetHomeFolder() {
    QDir userHome = QDir::home();
    if (!userHome.exists(DRAKO_DIR_NAME)) {
        qInfo() << "Creating " << DRAKO_DIR_NAME << "home directory in " << userHome.path();
        userHome.mkdir(DRAKO_DIR_NAME);
    }
    userHome.cd(DRAKO_DIR_NAME);
    DRAKO_DIR = userHome;
    qDebug() << "Drako home dir is " << DRAKO_DIR.path();
};

QDir FsUtil::createSiteFolderIfNeeded(QString siteUrl) {
    if(!DRAKO_DIR.exists(siteUrl)) {
        qInfo() << "Creating " << siteUrl << "in " << DRAKO_DIR.path();
        DRAKO_DIR.mkdir(siteUrl);
    }
    QDir siteDir(DRAKO_DIR);
    siteDir.cd(siteUrl);
    return siteDir;
}

QFileInfo FsUtil::getMainQmlFile(QString siteUrl) {
    QDir siteDir(DRAKO_DIR);
    siteDir.cd(siteUrl);
    QFileInfo mainQmlFile(siteDir, "main.qml");
    return mainQmlFile;
}
