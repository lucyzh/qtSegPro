#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <QObject>
#include <QFileDialog>
#include <QDebug>
#include <QtQuick>
#include <vector>
#include <QApplication>

typedef struct MyLine{
    QPoint startPnt;
    QPoint endPnt;
} myLine;

class ImageProcess: public QQuickItem
{
    Q_OBJECT
public:
    ImageProcess();
    ~ImageProcess();
//    void paintEvent(QPaintEvent* p);
//    void mousePressEvent(QMouseEvent *e);
//    void mouseMoveEvent(QMouseEvent *e);
//    void mouseReleaseEvent(QMouseEvent *e);

public:
//    QWidget *widget;
    QImage imageRes;
    int imagewidth;
    int imageheight;

    int qmlwidth;
    int qmlheight;
    QPoint startPnt;
    QPoint endPnt;
    bool isPressed;
    QVector<myLine*> points;
    QVector<myLine*> rects;
    QVector<myLine*> lines;

public:

    Q_INVOKABLE QImage openImage();
    Q_INVOKABLE QImage processImage();
    Q_INVOKABLE QImage recpaint();
    Q_INVOKABLE void setStartPnt(QPoint e);
    Q_INVOKABLE void setEndPnt(QPoint e);
    Q_INVOKABLE void getqmlmessage(int x , int y);
    Q_INVOKABLE void recrealtimeshow();
    Q_INVOKABLE void pntpaint();
    Q_INVOKABLE void pntpaintingstart();
signals:


};

#endif // IMAGEPROCESS_H
