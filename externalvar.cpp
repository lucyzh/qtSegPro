#include "externalvar.h"

//---------opencv libs--------

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h>
using namespace std;
using namespace cv;

QImage imageGlobal;
QImage imageSeg;

cv::Mat mask;
Rect rect;
QPoint recStarPoint;
QPoint recEndPoint;
vector<cv::Point> recpoints;

int iterCount;

const int BGD_KEY = EVENT_FLAG_CTRLKEY;
const int FGD_KEY = EVENT_FLAG_SHIFTKEY;

const Scalar RED = Scalar(0,0,255);
const Scalar PINK = Scalar(230,130,255);
const Scalar BLUE = Scalar(255,0,0);
const Scalar LIGHTBLUE = Scalar(255,255,160);
const Scalar GREEN = Scalar(0,255,0);

bool BGD_BTN;
bool FGD_BTN;
