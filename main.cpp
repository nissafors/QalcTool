#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>
#include <QDebug>

#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* mainQml = engine.rootObjects().first();
    QObject* inputTextArea = mainQml->findChild<QObject*>("inputTextArea");
    QObject* outputLabel = mainQml->findChild<QObject*>("outputLabel");

    Calculator calculator(inputTextArea, outputLabel);

    return app.exec();
}
