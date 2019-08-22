#include "imageprocess.h"
#include "externalvar.h"

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
                qDebug()<<imageRes;

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
