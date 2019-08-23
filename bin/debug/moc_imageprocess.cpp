/****************************************************************************
** Meta object code from reading C++ file 'imageprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imageprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcess_t {
    QByteArrayData data[14];
    char stringdata0[130];
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
QT_MOC_LITERAL(13, 113, 16) // "pntpaintingstart"

    },
    "ImageProcess\0openImage\0\0processImage\0"
    "recpaint\0setStartPnt\0e\0setEndPnt\0"
    "getqmlmessage\0x\0y\0recrealtimeshow\0"
    "pntpaint\0pntpaintingstart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcess[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x02 /* Public */,
       3,    0,   60,    2, 0x02 /* Public */,
       4,    0,   61,    2, 0x02 /* Public */,
       5,    1,   62,    2, 0x02 /* Public */,
       7,    1,   65,    2, 0x02 /* Public */,
       8,    2,   68,    2, 0x02 /* Public */,
      11,    0,   73,    2, 0x02 /* Public */,
      12,    0,   74,    2, 0x02 /* Public */,
      13,    0,   75,    2, 0x02 /* Public */,

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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
