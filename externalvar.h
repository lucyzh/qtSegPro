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
extern QImage imageOri;
extern QImage imageSeg;

extern cv::Mat mask;
extern QPoint recStarPoint;
extern QPoint recEndPoint;
extern vector<cv::Point> recpoints;
extern vector<cv::Point> fgPxls;
extern vector<cv::Point> bgPxls;
extern vector<cv::Point> fgdPxls, bgdPxls, prFgdPxls, prBgdPxls;
extern Rect rect;
extern const Mat* image;

extern int iterCount;

extern const Scalar RED;
extern const Scalar PINK;
extern const Scalar BLUE;
extern const Scalar LIGHTBLUE;
extern const Scalar GREEN;

extern bool BGD_BTN;
extern bool FGD_BTN;

#endif // EXTERNALVAR_H
