#include "externalvar.h"

QImage imageGlobal;
QImage imageSeg;

cv::Mat mask;
Rect rect;
QPoint recStarPoint;
QPoint recEndPoint;
vector<cv::Point> recpoints;

int iterCount;
