#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
//#include <QQuickView>
//#include <QQmlEngine>
#include "ColorImageProvider.cpp"
#include "imageprocess.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<ImageProcess>("Imagepro", 1, 1, "ImageProItem");

    engine.addImageProvider(QLatin1String("colors"), new ColorImageProvider);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    return app.exec();
}
