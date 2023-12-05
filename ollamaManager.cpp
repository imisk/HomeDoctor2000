#include "ollamaManager.h"

#include <QByteArray>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <iostream>

ollamaManager::ollamaManager(QWidget *parent)
    : QWidget{parent}
{
    
}

void ollamaManager::test()
{
    qDebug() << "ollamaManager::test";

    QUrl url("http://localhost:11434/api/generate");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    data["model"] = "mistral";
    data["stream"] = false; // Set to true for word-by-word output
    data["prompt"] = "What is the capital of France?";

    reply = networkMngr.post(request, QJsonDocument(data).toJson());

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString responseText = QString::fromUtf8(reply->readAll());
            qDebug() << "Response = " << responseText.toStdString();
        } else {
            qDebug() << "Error : " << reply->errorString().toStdString();
        }
        reply->deleteLater();
    });
}

void ollamaManager::runTest() {}
