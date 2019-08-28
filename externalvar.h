#ifndef EXTERNALVAR_H
#define EXTERNALVAR_H

#include <QImage>

extern QImage imageGlobal;
extern QImage imageSeg;

//---------opencv libs--------

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

extern cv::Mat mask;
extern Rect rect;


#endif // EXTERNALVAR_H
