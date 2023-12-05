#ifndef OLLAMAMANAGER_H
#define OLLAMAMANAGER_H

#include <QWidget>

#include <QByteArray>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <iostream>

class ollamaManager : public QWidget
{
    Q_OBJECT
public:
    explicit ollamaManager(QWidget *parent = nullptr);

    void test();
signals:

public slots:

    void runTest();

private:
    QJsonObject data;
    QNetworkAccessManager networkMngr;
    QNetworkReply *reply;
};

#endif // OLLAMAMANAGER_H
