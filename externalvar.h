#ifndef EXTERNALVAR_H
#define EXTERNALVAR_H

#include <QImage>
#include <iostream>

//---------opencv libs--------

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace std;
using namespace cv;


extern QImage imageGlobal;
extern QImage imageSeg;

extern cv::Mat mask;
extern Rect rect;
extern QPoint recStarPoint;
extern QPoint recEndPoint;
extern vector<cv::Point> recpoints;




#endif // EXTERNALVAR_H
