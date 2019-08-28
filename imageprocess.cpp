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
//    imageRes = QImage("C:/Users/SanguolianP/Desktop/imageTestqml4/qml/images/maininterface.jpg");
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
        if(fileName != "")
        {
            if(!QImage(fileName).isNull())
            {
                qDebug()<<fileName;
                imageRes = QImage(fileName);
                imageGlobal = imageRes;
                imagewidth = imageGlobal.width();
                imageheight = imageGlobal.height();
                qDebug()<<imageRes;
                qDebug()<<"imagewidth" << imagewidth << "  " <<"imageheight" << imageheight<< endl;
                return imageRes;
            }
        }
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
}

void ImageProcess::setEndPnt(QPoint e)
{
    endPnt.setX(e.x() * imagewidth/qmlwidth);
    endPnt.setY(e.y() * imageheight/(qmlheight*0.8) );
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
    cvtColor(ori,img,CV_BGRA2BGR);
//    mask.create(img.size(),CV_8UC1);
    setRectInMask(img);
    cv::Rect rect(/*rc_x*/ 200,/*rc_y*/ 100,/*rc_width*/ 600,/*rc_height*/ 800);
    cv::grabCut(img, mask,rect,bgmodel,fgmodel,/*iteration*/1,GC_INIT_WITH_RECT);
    cv::compare(mask,cv::GC_PR_FGD,mask, cv::CMP_EQ);
    cv::Mat fgd(img.size(), CV_8UC3, cv::Scalar(128,128,128));
    img.copyTo(fgd,mask);
    imageSeg = QImage((uchar*) fgd.data, fgd.cols, fgd.rows, fgd.step, QImage::Format_RGB888);
    return imageSeg;
}


void ImageProcess::setRectInMask(Mat img)
{
    mask.create(img.size(), CV_8UC1);
}
