#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "keypad.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    KEYPAD keypad;

    engine.rootContext()->setContextProperty("Keypad", &keypad);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    keypad.serialRead();

    return app.exec();
}
