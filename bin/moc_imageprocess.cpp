/****************************************************************************
** Meta object code from reading C++ file 'imageprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../imageprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcess_t {
    QByteArrayData data[47];
    char stringdata0[481];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcess_t qt_meta_stringdata_ImageProcess = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImageProcess"
QT_MOC_LITERAL(1, 13, 9), // "openImage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "openLabel"
QT_MOC_LITERAL(4, 34, 12), // "processImage"
QT_MOC_LITERAL(5, 47, 11), // "setStartPnt"
QT_MOC_LITERAL(6, 59, 1), // "e"
QT_MOC_LITERAL(7, 61, 9), // "setEndPnt"
QT_MOC_LITERAL(8, 71, 14), // "setRecStartPnt"
QT_MOC_LITERAL(9, 86, 13), // "setRectEndPnt"
QT_MOC_LITERAL(10, 100, 13), // "getqmlmessage"
QT_MOC_LITERAL(11, 114, 1), // "x"
QT_MOC_LITERAL(12, 116, 1), // "y"
QT_MOC_LITERAL(13, 118, 15), // "recrealtimeshow"
QT_MOC_LITERAL(14, 134, 8), // "pntpaint"
QT_MOC_LITERAL(15, 143, 16), // "pntpaintingstart"
QT_MOC_LITERAL(16, 160, 11), // "pntpaintend"
QT_MOC_LITERAL(17, 172, 5), // "clear"
QT_MOC_LITERAL(18, 178, 7), // "rePaint"
QT_MOC_LITERAL(19, 186, 4), // "undo"
QT_MOC_LITERAL(20, 191, 13), // "recPaintStart"
QT_MOC_LITERAL(21, 205, 13), // "getModelParam"
QT_MOC_LITERAL(22, 219, 11), // "initialRect"
QT_MOC_LITERAL(23, 231, 11), // "getRecPoint"
QT_MOC_LITERAL(24, 243, 17), // "vector<cv::Point>"
QT_MOC_LITERAL(25, 261, 13), // "setRectInMask"
QT_MOC_LITERAL(26, 275, 11), // "setfgInMask"
QT_MOC_LITERAL(27, 287, 11), // "setbgInMask"
QT_MOC_LITERAL(28, 299, 21), // "convertQPoint2cvPoint"
QT_MOC_LITERAL(29, 321, 9), // "cv::Point"
QT_MOC_LITERAL(30, 331, 5), // "reset"
QT_MOC_LITERAL(31, 337, 8), // "nextIter"
QT_MOC_LITERAL(32, 346, 9), // "showImage"
QT_MOC_LITERAL(33, 356, 15), // "updateIterCount"
QT_MOC_LITERAL(34, 372, 8), // "startSeg"
QT_MOC_LITERAL(35, 381, 9), // "startSeg1"
QT_MOC_LITERAL(36, 391, 7), // "saveSeg"
QT_MOC_LITERAL(37, 399, 9), // "getfgPxls"
QT_MOC_LITERAL(38, 409, 9), // "getbgPxls"
QT_MOC_LITERAL(39, 419, 8), // "setImage"
QT_MOC_LITERAL(40, 428, 3), // "Mat"
QT_MOC_LITERAL(41, 432, 6), // "_image"
QT_MOC_LITERAL(42, 439, 9), // "setPrMask"
QT_MOC_LITERAL(43, 449, 10), // "getBinMask"
QT_MOC_LITERAL(44, 460, 7), // "comMask"
QT_MOC_LITERAL(45, 468, 4), // "Mat&"
QT_MOC_LITERAL(46, 473, 7) // "binMask"

    },
    "ImageProcess\0openImage\0\0openLabel\0"
    "processImage\0setStartPnt\0e\0setEndPnt\0"
    "setRecStartPnt\0setRectEndPnt\0getqmlmessage\0"
    "x\0y\0recrealtimeshow\0pntpaint\0"
    "pntpaintingstart\0pntpaintend\0clear\0"
    "rePaint\0undo\0recPaintStart\0getModelParam\0"
    "initialRect\0getRecPoint\0vector<cv::Point>\0"
    "setRectInMask\0setfgInMask\0setbgInMask\0"
    "convertQPoint2cvPoint\0cv::Point\0reset\0"
    "nextIter\0showImage\0updateIterCount\0"
    "startSeg\0startSeg1\0saveSeg\0getfgPxls\0"
    "getbgPxls\0setImage\0Mat\0_image\0setPrMask\0"
    "getBinMask\0comMask\0Mat&\0binMask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x02 /* Public */,
       3,    0,  190,    2, 0x02 /* Public */,
       4,    0,  191,    2, 0x02 /* Public */,
       5,    1,  192,    2, 0x02 /* Public */,
       7,    1,  195,    2, 0x02 /* Public */,
       8,    1,  198,    2, 0x02 /* Public */,
       9,    1,  201,    2, 0x02 /* Public */,
      10,    2,  204,    2, 0x02 /* Public */,
      13,    0,  209,    2, 0x02 /* Public */,
      14,    1,  210,    2, 0x02 /* Public */,
      15,    0,  213,    2, 0x02 /* Public */,
      16,    0,  214,    2, 0x02 /* Public */,
      17,    0,  215,    2, 0x02 /* Public */,
      18,    0,  216,    2, 0x02 /* Public */,
      19,    0,  217,    2, 0x02 /* Public */,
      20,    0,  218,    2, 0x02 /* Public */,
      21,    1,  219,    2, 0x02 /* Public */,
      22,    0,  222,    2, 0x02 /* Public */,
      23,    0,  223,    2, 0x02 /* Public */,
      25,    0,  224,    2, 0x02 /* Public */,
      26,    0,  225,    2, 0x02 /* Public */,
      27,    0,  226,    2, 0x02 /* Public */,
      28,    1,  227,    2, 0x02 /* Public */,
      30,    0,  230,    2, 0x02 /* Public */,
      31,    0,  231,    2, 0x02 /* Public */,
      32,    0,  232,    2, 0x02 /* Public */,
      33,    0,  233,    2, 0x02 /* Public */,
      34,    0,  234,    2, 0x02 /* Public */,
      35,    0,  235,    2, 0x02 /* Public */,
      36,    0,  236,    2, 0x02 /* Public */,
      37,    0,  237,    2, 0x02 /* Public */,
      38,    0,  238,    2, 0x02 /* Public */,
      39,    1,  239,    2, 0x02 /* Public */,
      42,    0,  242,    2, 0x02 /* Public */,
      43,    2,  243,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QImage,
    QMetaType::QImage,
    QMetaType::QImage,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    0x80000000 | 24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 29, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40, 0x80000000 | 45,   44,   46,

       0        // eod
};

void ImageProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QImage _r = _t->openImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 1: { QImage _r = _t->openLabel();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 2: { QImage _r = _t->processImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setStartPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->setEndPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->setRecStartPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->setRectEndPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->getqmlmessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->recrealtimeshow(); break;
        case 9: _t->pntpaint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->pntpaintingstart(); break;
        case 11: _t->pntpaintend(); break;
        case 12: _t->clear(); break;
        case 13: _t->rePaint(); break;
        case 14: _t->undo(); break;
        case 15: { QImage _r = _t->recPaintStart();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->getModelParam((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->initialRect(); break;
        case 18: { vector<cv::Point> _r = _t->getRecPoint();
            if (_a[0]) *reinterpret_cast< vector<cv::Point>*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->setRectInMask(); break;
        case 20: _t->setfgInMask(); break;
        case 21: _t->setbgInMask(); break;
        case 22: { cv::Point _r = _t->convertQPoint2cvPoint((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< cv::Point*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->reset(); break;
        case 24: { int _r = _t->nextIter();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->showImage(); break;
        case 26: { int _r = _t->updateIterCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->startSeg(); break;
        case 28: _t->startSeg1(); break;
        case 29: _t->saveSeg(); break;
        case 30: _t->getfgPxls(); break;
        case 31: _t->getbgPxls(); break;
        case 32: _t->setImage((*reinterpret_cast< const Mat(*)>(_a[1]))); break;
        case 33: _t->setPrMask(); break;
        case 34: _t->getBinMask((*reinterpret_cast< const Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageProcess::staticMetaObject = { {
    &QQuickItem::staticMetaObject,
    qt_meta_stringdata_ImageProcess.data,
    qt_meta_data_ImageProcess,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcess.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ImageProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
