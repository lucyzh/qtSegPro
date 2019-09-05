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
    QByteArrayData data[37];
    char stringdata0[368];
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
QT_MOC_LITERAL(3, 24, 12), // "processImage"
QT_MOC_LITERAL(4, 37, 8), // "recpaint"
QT_MOC_LITERAL(5, 46, 11), // "setStartPnt"
QT_MOC_LITERAL(6, 58, 1), // "e"
QT_MOC_LITERAL(7, 60, 9), // "setEndPnt"
QT_MOC_LITERAL(8, 70, 13), // "getqmlmessage"
QT_MOC_LITERAL(9, 84, 1), // "x"
QT_MOC_LITERAL(10, 86, 1), // "y"
QT_MOC_LITERAL(11, 88, 15), // "recrealtimeshow"
QT_MOC_LITERAL(12, 104, 8), // "pntpaint"
QT_MOC_LITERAL(13, 113, 16), // "pntpaintingstart"
QT_MOC_LITERAL(14, 130, 13), // "getModelParam"
QT_MOC_LITERAL(15, 144, 8), // "startSeg"
QT_MOC_LITERAL(16, 153, 11), // "initialRect"
QT_MOC_LITERAL(17, 165, 11), // "getRecPoint"
QT_MOC_LITERAL(18, 177, 17), // "vector<cv::Point>"
QT_MOC_LITERAL(19, 195, 13), // "setRectInMask"
QT_MOC_LITERAL(20, 209, 7), // "cv::Mat"
QT_MOC_LITERAL(21, 217, 11), // "setfgInMask"
QT_MOC_LITERAL(22, 229, 5), // "Point"
QT_MOC_LITERAL(23, 235, 1), // "p"
QT_MOC_LITERAL(24, 237, 11), // "setbgInMask"
QT_MOC_LITERAL(25, 249, 21), // "convertQPoint2cvPoint"
QT_MOC_LITERAL(26, 271, 9), // "cv::Point"
QT_MOC_LITERAL(27, 281, 5), // "reset"
QT_MOC_LITERAL(28, 287, 8), // "nextIter"
QT_MOC_LITERAL(29, 296, 9), // "showImage"
QT_MOC_LITERAL(30, 306, 15), // "updateIterCount"
QT_MOC_LITERAL(31, 322, 9), // "startSeg1"
QT_MOC_LITERAL(32, 332, 10), // "getBinMask"
QT_MOC_LITERAL(33, 343, 3), // "Mat"
QT_MOC_LITERAL(34, 347, 7), // "comMask"
QT_MOC_LITERAL(35, 355, 4), // "Mat&"
QT_MOC_LITERAL(36, 360, 7) // "binMask"

    },
    "ImageProcess\0openImage\0\0processImage\0"
    "recpaint\0setStartPnt\0e\0setEndPnt\0"
    "getqmlmessage\0x\0y\0recrealtimeshow\0"
    "pntpaint\0pntpaintingstart\0getModelParam\0"
    "startSeg\0initialRect\0getRecPoint\0"
    "vector<cv::Point>\0setRectInMask\0cv::Mat\0"
    "setfgInMask\0Point\0p\0setbgInMask\0"
    "convertQPoint2cvPoint\0cv::Point\0reset\0"
    "nextIter\0showImage\0updateIterCount\0"
    "startSeg1\0getBinMask\0Mat\0comMask\0Mat&\0"
    "binMask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x02 /* Public */,
       3,    0,  130,    2, 0x02 /* Public */,
       4,    0,  131,    2, 0x02 /* Public */,
       5,    1,  132,    2, 0x02 /* Public */,
       7,    1,  135,    2, 0x02 /* Public */,
       8,    2,  138,    2, 0x02 /* Public */,
      11,    0,  143,    2, 0x02 /* Public */,
      12,    0,  144,    2, 0x02 /* Public */,
      13,    0,  145,    2, 0x02 /* Public */,
      14,    1,  146,    2, 0x02 /* Public */,
      15,    0,  149,    2, 0x02 /* Public */,
      16,    0,  150,    2, 0x02 /* Public */,
      17,    0,  151,    2, 0x02 /* Public */,
      19,    1,  152,    2, 0x02 /* Public */,
      21,    1,  155,    2, 0x02 /* Public */,
      24,    1,  158,    2, 0x02 /* Public */,
      25,    1,  161,    2, 0x02 /* Public */,
      27,    0,  164,    2, 0x02 /* Public */,
      28,    0,  165,    2, 0x02 /* Public */,
      29,    0,  166,    2, 0x02 /* Public */,
      30,    0,  167,    2, 0x02 /* Public */,
      31,    0,  168,    2, 0x02 /* Public */,
      32,    2,  169,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QImage,
    QMetaType::QImage,
    QMetaType::QImage,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::QImage,
    QMetaType::Void,
    0x80000000 | 18,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 22,   23,
    0x80000000 | 26, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QImage,
    QMetaType::Void, 0x80000000 | 33, 0x80000000 | 35,   34,   36,

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
        case 1: { QImage _r = _t->processImage();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 2: { QImage _r = _t->recpaint();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setStartPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->setEndPnt((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->getqmlmessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->recrealtimeshow(); break;
        case 7: _t->pntpaint(); break;
        case 8: _t->pntpaintingstart(); break;
        case 9: _t->getModelParam((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: { QImage _r = _t->startSeg();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->initialRect(); break;
        case 12: { vector<cv::Point> _r = _t->getRecPoint();
            if (_a[0]) *reinterpret_cast< vector<cv::Point>*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->setRectInMask((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 14: _t->setfgInMask((*reinterpret_cast< Point(*)>(_a[1]))); break;
        case 15: _t->setbgInMask((*reinterpret_cast< Point(*)>(_a[1]))); break;
        case 16: { cv::Point _r = _t->convertQPoint2cvPoint((*reinterpret_cast< QPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< cv::Point*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->reset(); break;
        case 18: { int _r = _t->nextIter();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->showImage(); break;
        case 20: { int _r = _t->updateIterCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { QImage _r = _t->startSeg1();
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->getBinMask((*reinterpret_cast< const Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
