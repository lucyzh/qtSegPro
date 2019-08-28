#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
//#include <QQuickView>
//#include <QQmlEngine>
#include "colorimageprovider.cpp"
#include "imageprocess.h"
#include "grabCut.h"

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
//    cv::Mat img = imread("/Users/lucy/Desktop/a/105232.jpg");
//    namedWindow("img",WINDOW_AUTOSIZE);
//    imshow("img",img);
//    waitKey(0);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<ImageProcess>("Imagepro", 1, 1, "ImageProItem");

    engine.addImageProvider(QLatin1String("imgProvider"), new ColorImageProvider);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    return app.exec();
}
