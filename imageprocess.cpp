#include "imageprocess.h"
#include "externalvar.h"

#include <QMainWindow>
#include <vector>
#include <QMouseEvent>
#include <QPushButton>
#include <QFont>
#include <QPainter>

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
    QString fileName = QFileDialog::getOpenFileName(
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

//    for(int i = 0;i<lines.size();i++){              //重绘时需要画出所有线
//        myLine* pLine = lines[i];
//        painter.drawLine(pLine->startPnt,pLine->endPnt);
//    }
//    for(int i = 0;i<points.size();i++){
//        myLine* pLine = points[i];
//        painter.drawLine(pLine->startPnt,pLine->endPnt);
//    }

//    for(int i=0;i<rects.size();i++)
//    {
//        myLine* pLine = rects[i];
//        QPoint point1;      //左下
//        QPoint point2;      //右上
//        point1.setX(pLine->startPnt.x());
//        point1.setY(pLine->endPnt.y());

//        point2.setX(pLine->endPnt.x());
//        point2.setY(pLine->startPnt.y());
//        painter.drawLine(pLine->startPnt,point1);
//        painter.drawLine(pLine->startPnt,point2);
//        painter.drawLine(point1,pLine->endPnt);
//        painter.drawLine(point2,pLine->endPnt);
//    }

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
