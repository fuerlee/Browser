#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "siteloader.h"
#include "loadresulttype.h"
#include "fsutil.h"


int main(int argc, char *argv[])
{
    FsUtil::createAndSetHomeFolder();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterType<SiteLoader>("com.drako", 1, 0, "SiteLoader");
    qmlRegisterType<LoadResultType>("com.drako", 1, 0, "LoadResultType");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}