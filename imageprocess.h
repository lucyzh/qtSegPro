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
    Mat bgmodel, fgmodel;
    QString fileName;

    bool isInitialized;
    enum {NOT_SET = 0, IN_PROGRESS = 1, SET = 2};
    static const int radius = 1;
    static const int thickness = -1;
    uchar rectState, lblsState, prLblsState;


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
    Q_INVOKABLE void setRecStartPnt(QPoint);
    Q_INVOKABLE void setRectEndPnt(QPoint);
    Q_INVOKABLE void getqmlmessage(int x , int y);
    Q_INVOKABLE void recrealtimeshow();
    Q_INVOKABLE void pntpaint(int);
    Q_INVOKABLE void pntpaintingstart();

    Q_INVOKABLE void getModelParam(QString);

    //--------------grabCut----------------
    Q_INVOKABLE QImage startSeg();
    Q_INVOKABLE void initialRect();
    Q_INVOKABLE vector<cv::Point> getRecPoint();
    Q_INVOKABLE void setRectInMask();
    Q_INVOKABLE void setfgInMask();
    Q_INVOKABLE void setbgInMask();
    Q_INVOKABLE cv::Point convertQPoint2cvPoint(QPoint);
    Q_INVOKABLE void reset();
    Q_INVOKABLE int nextIter();
    Q_INVOKABLE void showImage() const;
    Q_INVOKABLE int updateIterCount();

    Q_INVOKABLE void startSeg1();
    Q_INVOKABLE void getfgPxls();
    Q_INVOKABLE vector<Point> getbgPxls();
    Q_INVOKABLE void setImage(const Mat& _image);

    //-------------State Change Methods---------------
    //...先不判空，实现最基本的功能


    //------------static methods---------------
    Q_INVOKABLE static void getBinMask(const Mat& comMask, Mat& binMask);


signals:


};

#endif // IMAGEPROCESS_H
