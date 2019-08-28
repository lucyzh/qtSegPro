//grabCut.h
#include <QObject>
#include <QDebug>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

class GCApplication:public QObject
{
    Q_OBJECT
public:
    GCApplication(QObject *parent = nullptr);

    ~GCApplication();

};
