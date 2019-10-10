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
    imageOri = imageRes;
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
    //QImage paintImg = imageGlobal;
    QPainter painter(&imageGlobal);
    QPen pen;
    qDebug() << "startpnt" << startPnt.x()<< "   " << startPnt.y()<<endl;
    qDebug() << "endpnt" << endPnt.x() << "   "<< endPnt.y() << endl;
    pen.setColor(Qt::green);
    pen.setWidth(1);
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
    return imageGlobal;
}//直接在imageGlobal上标记会导致最终的分割图颜色叠加，出现不正确的情况

void ImageProcess::setStartPnt(QPoint e)
{
    double tempHeight = qmlheight*0.8;
    //设置起始点 ，要先乘后除防止int类型相除之后小于1变成了0，高度乘以0.8是因为图片在qml前端显示是宽度占满，高度下方空余20%位置来放参数输入框
    if((double)imagewidth/(double)imageheight >= (double)qmlwidth/(double)tempHeight)
    {
        startPnt.setX(e.x() * imagewidth/qmlwidth);
        int picHeightInQml = qmlwidth*imageheight/imagewidth;
        int topline = (tempHeight-picHeightInQml) / 2;
        startPnt.setY( (e.y()-topline)*imageheight / picHeightInQml );
    }
    else
    {
        startPnt.setY(e.y() * imageheight/tempHeight );
        int picWidthInQml = tempHeight*imagewidth/imageheight;
        int leftline = (qmlwidth-picWidthInQml) / 2;
        startPnt.setX( (e.x()-leftline)*imagewidth / picWidthInQml);
    }
//    startPnt.setX(e.x() * imagewidth/qmlwidth);
//    startPnt.setY(e.y() * imageheight/(qmlheight) );
}

void ImageProcess::setEndPnt(QPoint e)
{
    double tempHeight = qmlheight*0.8;
    //设置起始点 ，要先乘后除防止int类型相除之后小于1变成了0，高度乘以0.8是因为图片在qml前端显示是宽度占满，高度下方空余20%位置来放参数输入框
    if((double)imagewidth/(double)imageheight >= (double)qmlwidth/(double)tempHeight)
    {
        endPnt.setX(e.x() * imagewidth/qmlwidth);
        int picHeightInQml = qmlwidth*imageheight/imagewidth;
        int topline = (tempHeight-picHeightInQml) / 2;
        endPnt.setY( (e.y()-topline)*imageheight / picHeightInQml );
    }
    else
    {
        endPnt.setY(e.y() * imageheight/tempHeight );
        int picWidthInQml = tempHeight*imagewidth/imageheight;
        int leftline = (qmlwidth-picWidthInQml) / 2;
        endPnt.setX( (e.x()-leftline)*imagewidth / picWidthInQml);
    }
}

void ImageProcess::setRecStartPnt(QPoint e)
{
    double tempHeight = qmlheight*0.8;
    //设置起始点 ，要先乘后除防止int类型相除之后小于1变成了0，高度乘以0.8是因为图片在qml前端显示是宽度占满，高度下方空余20%位置来放参数输入框
    if((double)imagewidth/(double)imageheight >= (double)qmlwidth/(double)tempHeight)
    {
        recStarPoint.setX(e.x() * imagewidth/qmlwidth);
        int picHeightInQml = qmlwidth*imageheight/imagewidth;
        int topline = (tempHeight-picHeightInQml) / 2;
        recStarPoint.setY( (e.y()-topline)*imageheight / picHeightInQml );
    }
    else
    {
        recStarPoint.setY(e.y() * imageheight/tempHeight );
        int picWidthInQml = tempHeight*imagewidth/imageheight;
        int leftline = (qmlwidth-picWidthInQml) / 2;
        recStarPoint.setX( (e.x()-leftline)*imagewidth / picWidthInQml);
    }
}

void ImageProcess::setRectEndPnt(QPoint e)
{
    double tempHeight = qmlheight*0.8;
    //设置起始点 ，要先乘后除防止int类型相除之后小于1变成了0，高度乘以0.8是因为图片在qml前端显示是宽度占满，高度下方空余20%位置来放参数输入框
    if((double)imagewidth/(double)imageheight >= (double)qmlwidth/(double)tempHeight)
    {
        recEndPoint.setX(e.x() * imagewidth/qmlwidth);
        int picHeightInQml = qmlwidth*imageheight/imagewidth;
        int topline = (tempHeight-picHeightInQml) / 2;
        recEndPoint.setY( (e.y()-topline)*imageheight / picHeightInQml );
    }
    else
    {
        recEndPoint.setY(e.y() * imageheight/tempHeight );
        int picWidthInQml = tempHeight*imagewidth/imageheight;
        int leftline = (qmlwidth-picWidthInQml) / 2;
        recEndPoint.setX( (e.x()-leftline)*imagewidth / picWidthInQml);
    }
}

void ImageProcess::getqmlmessage(int x, int y)
{
    qmlwidth = x ;
    qmlheight = y ;
}

void  ImageProcess::recrealtimeshow()
{

}

void  ImageProcess::pntpaint(int color_flag)
{
    QPainter painter(&imageGlobal);
    QPen pen;
    pen.setColor((Qt::GlobalColor)(color_flag));
    qDebug() << "qt.globalcolor: " << (Qt::GlobalColor)(color_flag) << endl;
    pen.setWidth(1);
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

void ImageProcess::getfgPxls()
{
    for(int i=0;i<points.length();i++){
        cv::Point pnStart = convertQPoint2cvPoint(points[i]->startPnt);
        cv::Point pnEnd = convertQPoint2cvPoint(points[i]->endPnt);
        fgdPxls.push_back(pnStart);
        fgdPxls.push_back(pnEnd);
    }
}

void ImageProcess::setfgInMask()
{
    vector<Point>::iterator it;
    for(it=fgdPxls.begin();it!=fgdPxls.end();++it)
        circle(mask, *it, radius, GC_FGD, thickness);
}

void ImageProcess::getbgPxls()
{
    for(int i=0;i<points.length();i++){
        cv::Point pnStart = convertQPoint2cvPoint(points[i]->startPnt);
        cv::Point pnEnd = convertQPoint2cvPoint(points[i]->endPnt);
        bgdPxls.push_back(pnStart);
        bgdPxls.push_back(pnEnd);
    }
}

void ImageProcess::setbgInMask()
{
    vector<Point>::iterator it;
    for(it=bgdPxls.begin();it!=bgdPxls.end();++it)
        circle(mask, *it, radius, GC_BGD, thickness);
}

void ImageProcess::showImage() const{
    if (image->empty())
        return;
    Mat res;
    Mat binMask;
    if(isInitialized)
        image->copyTo(res);
    else {
        getBinMask(mask, binMask);
        image->copyTo(res,binMask);
    }
    vector<Point>::const_iterator it;

    qDebug() << "inside showImage bgdPxls: " << bgdPxls.size() << endl;

    for(it = bgdPxls.begin(); it != bgdPxls.end(); ++it){
        circle(res, *it, radius, BLUE, thickness);
    }
    for(it = fgdPxls.begin(); it != fgdPxls.end(); ++it)
        circle(res, *it, radius, RED, thickness);
    for(it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
        circle(res, *it, radius, LIGHTBLUE, thickness);
    for(it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
        circle(res, *it, radius, PINK, thickness);
    //if(rectState == IN_PROGRESS || rectState == SET)
    rectangle(res, Point(rect.x, rect.y), Point(rect.x + rect.width, rect.y + rect.height), GREEN, 2);
    imageSeg = QImage((uchar*) res.data, res.cols, res.rows, res.step, QImage::Format_RGB888);
}

//set the rectangle(GC_PR_FGD) on mask
void ImageProcess::setRectInMask()
{
    vector<cv::Point> vecpoints = getRecPoint();
    cv::Point star = vecpoints[0];
    cv::Point end = vecpoints[1];

    rect.x = max(0, star.x);
    rect.y = max(0, star.y);
    rect.width = min(end.x-star.x, image->cols-star.x);
    rect.height = min(end.y-star.y, image->rows-star.y);

    mask.create(image->size(), CV_8UC1);
    CV_Assert(!mask.empty());
    mask.setTo(GC_BGD);
    (mask(rect)).setTo(Scalar(GC_PR_FGD));
}

//read the image to deal with
void ImageProcess::setImage(const Mat &_image)
{
    image = &_image;
}

//seg the image with rectangle or mask
void ImageProcess::startSeg1()
{
    cv::Mat ori = QImage2cvMat(imageOri,true,false);

    Mat img;
    if(ori.type()==CV_8UC4){
        cvtColor(ori,img,COLOR_BGRA2RGB);
        qDebug() << "convert to CV_8UC3" << endl;
    }
    else if (ori.type()/8==CV_8UC3) {
        ori.copyTo(img);
    }
    setImage(img);
    setRectInMask();
//    cv::GC_BGD  == 0//表示是背景
//    cv::GC_PR_BGD  == 2//表示可能是背景
//    cv::GC_FGD  == 1//表示是前景
//    cv::GC_PR_FGD  == 3//表示可能是前景

    if (fgdPxls.size()>0 || bgdPxls.size()>0) {
        setfgInMask();
        setbgInMask();
        isInitialized = false;
        qDebug() << "seg with mask" << endl;
        for(int i = 0; i < 6; i++) {
            if ( isInitialized ) {
                cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1);
            }
            else {
                cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1,GC_INIT_WITH_MASK);
                isInitialized = true;
            }
        }
    }
    else {
        isInitialized = false;
        for(int i = 0; i < 4; i++) {
            if ( isInitialized ) {
                cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1);
            }
            else {
                cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1,GC_INIT_WITH_RECT);
                isInitialized = true;
            }
        }
    }

    mask = mask & 1;//&处理，保留GC_FGD, GC_PR_FGD
    cv::compare(mask,cv::GC_FGD, mask, cv::CMP_EQ);
    cv::Mat fgd(ori.size(), CV_8UC3, cv::Scalar(0,0,0));
    img.copyTo(fgd, mask);

    cv::Mat fgdRect = fgd(rect);
    imageSeg = QImage((uchar*) fgdRect.data, fgdRect.cols, fgdRect.rows, fgdRect.step, QImage::Format_RGB888);

    //imageSeg = QImage((uchar*) fgd.data, fgd.cols, fgd.rows, fgd.step, QImage::Format_RGB888);

    qDebug() << "seg finished!!!" << endl;
}

QImage ImageProcess::startSeg()
{
    cv::Mat ori = QImage2cvMat(imageOri,true,false);

    Mat img;
    if(ori.type()==CV_8UC4){
        cvtColor(ori,img,COLOR_BGRA2RGB);
        qDebug() << "convert to CV_8UC3" << endl;
    }
    else if (ori.type()/8==CV_8UC3) {
        ori.copyTo(img);
    }
    setImage(img);
    setRectInMask();
//    cv::GC_BGD  == 0//表示是背景
//    cv::GC_FGD  == 1//表示是前景
//    cv::GC_PR_BGD  == 2//表示可能是背景
//    cv::GC_PR_FGD  == 3//表示可能是前景

    if (fgdPxls.size()>0 || bgdPxls.size()>0) {
        setfgInMask();
        setbgInMask();
        qDebug() << "seg with mask" << endl;
        cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1,GC_INIT_WITH_MASK);
    }
    else {
        qDebug() << "seg with rect" << endl;
        cv::grabCut(*image, mask,rect,bgmodel,fgmodel,1,GC_INIT_WITH_RECT);
    }
    qDebug() << "inside grabCut rect.width: " << rect.width << ", rect.height: " << rect.height << endl;

    cv::compare(mask,cv::GC_PR_FGD, mask, cv::CMP_EQ);
    cv::Mat fgd(ori.size(), CV_8UC3, cv::Scalar(255,255,255));
    img.copyTo(fgd, mask);

    cv::Mat fgcRect = fgd(rect);

    imageSeg = QImage((uchar*) fgcRect.data, fgcRect.cols, fgcRect.rows, fgcRect.step, QImage::Format_RGB888);
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

