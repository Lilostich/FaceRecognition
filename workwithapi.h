#ifndef WORKWITHAPI_H
#define WORKWITHAPI_H

//#include "restapi.h"
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QFile>

#include <QObject>

class WorkWithApi : public QObject
{
    Q_OBJECT
public:
    explicit WorkWithApi(QObject *parent = nullptr);

//    RestApi restApi;

    void login();
    void onManagerFinished(QNetworkReply *reply);

private:
    QString email;
    QString password;
    QString token;
    QString host;

    QNetworkAccessManager manager;

};

#endif // WORKWITHAPI_H
