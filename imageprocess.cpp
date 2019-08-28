#include "imageprocess.h"
#include "externalvar.h"

#include <QMainWindow>
#include <vector>
#include <QMouseEvent>
#include <QPushButton>
#include <QFont>
#include <QPainter>

//---------opencv libs--------

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>

#include <iostream>

//---------external file------------
#include "convert.h"

using namespace std;
using namespace cv;

ImageProcess::ImageProcess()
{

}

ImageProcess::~ImageProcess()
{

}

QImage ImageProcess::openImage()
{
    qDebug("open");
    fileName = QFileDialog::getOpenFileName(
                nullptr, "open image file",
                    ".",
                    "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    qDebug()<<fileName;
    imageRes = QImage(fileName);
    imageGlobal = imageRes;
    imagewidth = imageGlobal.width();
    imageheight = imageGlobal.height();
    qDebug()<<imageRes;
    qDebug()<<"imagewidth" << imagewidth << "  " <<"imageheight" << imageheight<< endl;
    return imageRes;
}

QImage ImageProcess::processImage()
{

    qDebug()<<"imageResimageResimageResimageRes+++++++++++++++"<<imageRes;
    qDebug("processed");
    return imageRes;
}


QImage ImageProcess::recpaint()
{
    QPainter painter(&imageGlobal);
    QPen pen;
    qDebug() << "startpnt" << startPnt.x()<< "   " << startPnt.y()<<endl;
    qDebug() << "endpnt" << endPnt.x() << "   "<< endPnt.y() << endl;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter.setPen(pen);


    QPoint point1;      //左下
    QPoint point2;      //右上
    point1.setX(startPnt.x());
    point1.setY(endPnt.y());

    point2.setX(endPnt.x());
    point2.setY(startPnt.y());
    painter.drawLine(startPnt,point1);
    painter.drawLine(startPnt,point2);
    painter.drawLine(point1,endPnt);
    painter.drawLine(point2,endPnt);
    qDebug()<<"imageResimageResimageResimageRes+++++++++++++++"<<imageRes;
    qDebug("processed");
    return imageGlobal;
}

void ImageProcess::setStartPnt(QPoint e)
{
    qDebug() << "starte" << e.x()<< "   " << e.y()<<endl;
    startPnt.setX(e.x() * imagewidth/qmlwidth);
    startPnt.setY(e.y()* imageheight/(qmlheight*0.8) );
    recStarPoint = startPnt;
}

void ImageProcess::setEndPnt(QPoint e)
{
    endPnt.setX(e.x() * imagewidth/qmlwidth);
    endPnt.setY(e.y() * imageheight/(qmlheight*0.8) );
    recEndPoint = endPnt;
}
void ImageProcess::getqmlmessage(int x, int y)
{

    qmlwidth = x ;
    qmlheight = y ;
    qDebug() << "qmlmess" << qmlwidth<< "   " <<qmlheight <<endl;
}

void  ImageProcess::recrealtimeshow()
{
//    update();
}

void  ImageProcess::pntpaint()
{
    QPainter painter(&imageGlobal);
    QPen pen;
    qDebug() << "startpnt" << startPnt.x()<< "   " << startPnt.y()<<endl;
    qDebug() << "endpnt" << endPnt.x() << "   "<< endPnt.y() << endl;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawLine(points[points.size()-1]->startPnt,endPnt);
    myLine *point = new myLine;
    point->startPnt = startPnt;
    point->endPnt = endPnt;
    points.push_back(point);
}

void ImageProcess::pntpaintingstart()
{
    myLine *point = new myLine;
    point->startPnt = startPnt;
    point->endPnt = endPnt;
    points.push_back(point);
}
//void ImageProcess::mousePressEvent(QMouseEvent *e)
//{

//      startPnt = e->pos();
//      endPnt = e->pos();
//      isPressed = true;
//      update();
//}

QImage ImageProcess::startSeg()
{
    cv::Mat ori = QImage2cvMat(imageGlobal,true,false);
    cv::Mat img;
    vector<cv::Point> vecpoints = getRecPoint();
    cv::Point star = vecpoints[0];
    cv::Point end = vecpoints[1];

    if(ori.type()==CV_8UC4){
        cvtColor(ori,img,CV_BGRA2BGR);
    }
    else if (ori.type()/8==CV_8UC3) {
        ori.copyTo(img);
    }

    mask.create(img.size(), CV_8UC1);

    cv::Rect rect(star.x, star.y, end.x-star.x, end.y-star.y);
    cv::grabCut(img, mask,rect,bgmodel,fgmodel,/*iteration*/1,GC_INIT_WITH_RECT);
    cv::compare(mask,cv::GC_PR_FGD, mask, cv::CMP_EQ);
    cv::Mat fgd(img.size(), CV_8UC3, cv::Scalar(255,255,255));
    img.copyTo(fgd, mask);
    imageSeg = QImage((uchar*) fgd.data, fgd.cols, fgd.rows, fgd.step, QImage::Format_RGB888);
    qDebug() << "seg finished!!!" << endl;
    return imageSeg;
}

vector<cv::Point> ImageProcess::getRecPoint()
{
    vector<cv::Point> vecpoints;
    cv::Point recPoint1(recStarPoint.x(), recStarPoint.y());
    cv::Point recPoint2(recEndPoint.x(), recEndPoint.y());
    qDebug() << "p1.x(): " << recPoint1.x << endl;
    qDebug() << "p2.x(): " << recPoint1.x << endl;
    vecpoints.push_back(recPoint1);
    vecpoints.push_back(recPoint2);
    return vecpoints;
}


void ImageProcess::setRectInMask(Mat img)
{
//    vector<cv::Point> vecpoints = getRecPoint();
//    cv::Point star = vecpoints[0];
//    cv::Point end = vecpoints[1];
//    mask.create(img.size(), CV_8UC1);
//    rect = Rect(star, end);

//    rectangle(img, star, end, Scalar(0,255,0),1);
}

