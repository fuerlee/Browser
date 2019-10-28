#include "siteloader.h"
#include <stdio.h>
#include <curl/curl.h>
#include "loadresulttype.h"
#include "fsutil.h"

SiteLoader::SiteLoader(QObject *parent) : QObject(parent)
{
}

size_t writeData(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

size_t writeCallback(char *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append(contents, size * nmemb);
    return size * nmemb;
}

int SiteLoader::loadSite(QString siteUrl) {
    qInfo() << "Loading site" << siteUrl;
    CURLcode resultCode;
    FsUtil::createSiteFolderIfNeeded(siteUrl);
    QFileInfo mainQmlFile = FsUtil::getMainQmlFile(siteUrl);
    std::string mainQmlFileStr = mainQmlFile.filePath().toUtf8().constData();
    const char *mainQmlPath = mainQmlFileStr.c_str();
    QString mainQmlUrl = siteUrl + "/main.qml";
    qDebug() << "Loading main qml from" << mainQmlUrl << "to" << mainQmlPath;

    CURL *curl = curl_easy_init();
    FILE *fp = fopen(mainQmlPath, "wb");
    curl_easy_setopt(curl, CURLOPT_URL, mainQmlUrl.toStdString().c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    resultCode = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(fp);

    qInfo() << "Curl code" << resultCode;
    if (resultCode != 0) {
        qInfo() << "Error while loading a site" << siteUrl;
        return LoadResultType::ERROR;
    }
    return LoadResultType::SUCCESS;
}

QString SiteLoader::loadProperties(QString siteUrl) {
    qInfo() << "Loading site properties" << siteUrl;
    CURLcode resultCode;
    char *url = "http://localhost:8080/getProperties";
    std::string responseStr;

    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseStr);
    resultCode = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    qInfo() << "Curl code" << resultCode;
    if (resultCode != 0) {
        qInfo() << "Error while loading data" << siteUrl;
        return QString();
    }
    QString response = QString::fromStdString(responseStr);
    qInfo() << "Result data" << response;
    return response;
}

QString SiteLoader::getMainQmlPath(QString siteUrl) {
    return "file:" + FsUtil::getMainQmlFile(siteUrl).filePath();
}