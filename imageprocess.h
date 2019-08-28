#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QObject>
#include <QFileDialog>
#include <QDebug>
#include <QtQuick>
#include <vector>
#include <QApplication>

//---------opencv libs--------

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace std;
using namespace cv;

#include <iostream>

typedef struct MyLine{
    QPoint startPnt;
    QPoint endPnt;
} myLine;

class ImageProcess: public QQuickItem
{
    Q_OBJECT
public:
    ImageProcess();
    ~ImageProcess();
//    void paintEvent(QPaintEvent* p);
//    void mousePressEvent(QMouseEvent *e);
//    void mouseMoveEvent(QMouseEvent *e);
//    void mouseReleaseEvent(QMouseEvent *e);

public:
//    QWidget *widget;
    QImage imageRes;
    int imagewidth;
    int imageheight;

    //------------------grabCut params-------------
    Mat mask,bgmodel, fgmodel;
    QString fileName;

    int qmlwidth;
    int qmlheight;
    QPoint startPnt;
    QPoint endPnt;
    bool isPressed;
    QVector<myLine*> points;
    QVector<myLine*> rects;
    QVector<myLine*> lines;



public:

    Q_INVOKABLE QImage openImage();
    Q_INVOKABLE QImage processImage();
    Q_INVOKABLE QImage recpaint();
    Q_INVOKABLE void setStartPnt(QPoint e);
    Q_INVOKABLE void setEndPnt(QPoint e);
    Q_INVOKABLE void getqmlmessage(int x , int y);
    Q_INVOKABLE void recrealtimeshow();
    Q_INVOKABLE void pntpaint();
    Q_INVOKABLE void pntpaintingstart();

    //--------------grabCut----------------
    Q_INVOKABLE QImage startSeg();
    Q_INVOKABLE vector<cv::Point> getRecPoint();
    Q_INVOKABLE void setRectInMask(cv::Mat);

signals:


};

#endif // IMAGEPROCESS_H
