#include "workwithapi.h"

#include <QThread>

WorkWithApi::WorkWithApi(QObject *parent) : QObject(parent),
    email("lty99gjc@yandex.ru"),
    password("password"),
    token(""),
    host("https://backend.facecloud.tevian.ru/api/v1")
{
    connect(&manager, &QNetworkAccessManager::finished,
            this, &WorkWithApi::onManagerFinished);
}

void WorkWithApi::login()
{
    qDebug()<< "start login";
    QNetworkRequest request(QUrl("https://backend.facecloud.tevian.ru/api/v1/login"));
//    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("Content-Type", "application/json");
    QFile file("login.json");
    if(file.open(QIODevice::ReadOnly)){
        qDebug()<< "open file good";
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();
        qDebug() << obj["email"];
        qDebug() << obj["password"];
        doc.setObject(obj);
        auto res = manager.post(request, doc.toJson());
        qDebug() << res;
        qDebug() << "end login";
    }
}

void WorkWithApi::onManagerFinished(QNetworkReply *reply)
{
    qDebug() << "slot run";
    qDebug() << reply->readAll();
}
