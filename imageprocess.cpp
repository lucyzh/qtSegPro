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
void ImageProcess::initialRect()
{
    cv::Point p = convertQPoint2cvPoint(recStarPoint);
    cv::Rect rect(p.x, p.y, 1, 1);
    cv::Mat img = QImage2cvMat(imageGlobal,true,false);
    cv::rectangle(img, rect, RED, 1, LINE_8, 0);
}

void ImageProcess::getBinMask(const Mat &comMask, Mat &binMask)
{
    if( comMask.empty() || comMask.type()!=CV_8UC1 )
            CV_Error( Error::StsBadArg, "comMask is empty or has incorrect type (not CV_8UC1)" );
    if( binMask.empty() || binMask.rows!=comMask.rows || binMask.cols!=comMask.cols )
        binMask.create( comMask.size(), CV_8UC1 );
    binMask = comMask & 1;
}

void ImageProcess::setfgInMask(Point p)
{
    vector<Point> *fpxls;
    fpxls = &fgdPxls;
    fpxls->push_back(p);
    circle(mask, p, radius, GC_FGD, thickness);
}

void ImageProcess::setbgInMask(Point p)
{
    vector<Point> *bpxls;
    bpxls = &bgdPxls;
    bpxls->push_back(p);
    circle(mask, p, radius, GC_BGD, thickness);
}

void ImageProcess::showImage() const{
    if (image->empty())
        return;
    Mat res;
    Mat binMask;
    if(!isInitialized)
        image->copyTo(res);
    else {
        getBinMask(mask, binMask);
        image->copyTo(res,binMask);
    }
    vector<Point>::const_iterator it;
    for(it = bgdPxls.begin(); it != bgdPxls.end(); ++it)
        circle(res, *it, radius, BLUE, thickness);
    for(it = fgdPxls.begin(); it != fgdPxls.end(); ++it)
        circle(res, *it, radius, RED, thickness);
    for(it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
        circle(res, *it, radius, LIGHTBLUE, thickness);
    for(it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
        circle(res, *it, radius, PINK, thickness);
    if(rectState == IN_PROGRESS || rectState == SET)
        rectangle(res, Point(rect.x, rect.y), Point(rect.x + rect.width, rect.y + rect.height), GREEN, 1);
    imageSeg = QImage((uchar*) res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
}

void ImageProcess::setRectInMask(cv::Mat img)
{
    vector<cv::Point> vecpoints = getRecPoint();
    cv::Point star = vecpoints[0];
    cv::Point end = vecpoints[1];

    //cv::Rect rect(star.x, star.y, end.x-star.x, end.y-star.y);

    rect.x = max(0, star.x);
    rect.y = max(0, star.y);
    rect.width = min(end.x-star.x, img.cols-star.x);
    rect.height = min(end.y-star.y, img.rows-star.y);

    mask.create(img.size(), CV_8UC1);
    CV_Assert(!mask.empty());
    mask.setTo(GC_BGD);
    (mask(rect)).setTo(Scalar(GC_PR_FGD));
}

QImage ImageProcess::startSeg1()
{
    cv::Mat ori = QImage2cvMat(imageGlobal,true,false);
    cv::Mat img;
    if(ori.type()==CV_8UC4){
        cvtColor(ori,img,CV_BGRA2BGR);
    }
    else if (ori.type()/8==CV_8UC3) {
        ori.copyTo(img);
    }
    setRectInMask(img);
    cv::grabCut(img, mask,rect,bgmodel,fgmodel,3,GC_INIT_WITH_RECT);
    cv::compare(mask,cv::GC_PR_FGD, mask, cv::CMP_EQ);
    cv::Mat fgd(img.size(), CV_8UC3, cv::Scalar(255,255,255));
    img.copyTo(fgd, mask);
    imageSeg = QImage((uchar*) fgd.data, fgd.cols, fgd.rows, fgd.step, QImage::Format_RGB888);
    qDebug() << "iterCount: " << iterCount << endl;
    qDebug() << "seg finished!!!" << endl;
    return imageSeg;
}

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

    cv::grabCut(img, mask,rect,bgmodel,fgmodel,updateIterCount(),GC_INIT_WITH_RECT);
    cv::compare(mask,cv::GC_PR_FGD, mask, cv::CMP_EQ);
    cv::Mat fgd(img.size(), CV_8UC3, cv::Scalar(255,255,255));
    img.copyTo(fgd, mask);
    imageSeg = QImage((uchar*) fgd.data, fgd.cols, fgd.rows, fgd.step, QImage::Format_RGB888);
    qDebug() << "iterCount: " << iterCount << endl;
    qDebug() << "seg finished!!!" << endl;
    return imageSeg;
}

int ImageProcess::nextIter()
{
    cv::Mat ori = QImage2cvMat(imageGlobal,true,false);
    cv::Mat img;
    if(ori.type()==CV_8UC4){
        cvtColor(ori,img,CV_BGRA2BGR);
    }
    else if (ori.type()/8==CV_8UC3) {
        ori.copyTo(img);
    }

    if (isInitialized)
    {
        cv::grabCut(img,mask, rect, bgmodel, fgmodel, 1);
    }
    else {
        if(rectState != SET){
            return iterCount;
        }
        if(lblsState == SET || prLblsState == SET){
            grabCut(img,mask,rect,bgmodel,fgmodel,1,GC_INIT_WITH_MASK);
        }
        else {
            grabCut(img, mask, rect, bgmodel, fgmodel, 1, GC_INIT_WITH_RECT);
        }
        isInitialized = true;
    }
    iterCount++;
    bgdPxls.clear(); fgdPxls.clear();
    prBgdPxls.clear(); prFgdPxls.clear();

    return iterCount;
}

cv::Point ImageProcess::convertQPoint2cvPoint(QPoint qPoint)
{
    vector<cv::Point> vecpoint;
    cv::Point cvPot(qPoint.x(), qPoint.y());
    return cvPot;
}

void ImageProcess::reset()
{
    if(!mask.empty()){
        mask.setTo(Scalar::all(GC_BGD));
    }
    bgdPxls.clear(); fgdPxls.clear();
    prBgdPxls.clear(); prFgdPxls.clear();
    isInitialized = false;
    rectState = NOT_SET;
    lblsState = NOT_SET;
    prLblsState = NOT_SET;
}

vector<cv::Point> ImageProcess::getRecPoint()
{
    vector<cv::Point> vecpoints;
    cv::Point recPoint1 = convertQPoint2cvPoint(recStarPoint);
    cv::Point recPoint2 = convertQPoint2cvPoint(recEndPoint);
    vecpoints.push_back(recPoint1);
    vecpoints.push_back(recPoint2);
    return vecpoints;
}

void ImageProcess::getModelParam(QString param)
{
    iterCount = param.toInt();
}

int ImageProcess::updateIterCount()
{
    return iterCount;
}

