/****************************************************************************
** Meta object code from reading C++ file 'GLSatAbstractWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../satviewer/ogl/GLSatAbstractWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatAbstractWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLSatAbstractWidget_t {
    QByteArrayData data[17];
    char stringdata[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GLSatAbstractWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GLSatAbstractWidget_t qt_meta_stringdata_GLSatAbstractWidget = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 16),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 4),
QT_MOC_LITERAL(4, 43, 16),
QT_MOC_LITERAL(5, 60, 16),
QT_MOC_LITERAL(6, 77, 14),
QT_MOC_LITERAL(7, 92, 10),
QT_MOC_LITERAL(8, 103, 3),
QT_MOC_LITERAL(9, 107, 9),
QT_MOC_LITERAL(10, 117, 3),
QT_MOC_LITERAL(11, 121, 7),
QT_MOC_LITERAL(12, 129, 4),
QT_MOC_LITERAL(13, 134, 6),
QT_MOC_LITERAL(14, 141, 5),
QT_MOC_LITERAL(15, 147, 6),
QT_MOC_LITERAL(16, 154, 6)
    },
    "GLSatAbstractWidget\0statusZRVChanged\0"
    "\0text\0doubleClickedSat\0doubleClickedLoc\0"
    "currentChanged\0Satellite*\0sat\0Location*\0"
    "loc\0double*\0time\0zoomed\0value\0movedX\0"
    "movedY\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLSatAbstractWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       4,    0,   52,    2, 0x05,
       5,    0,   53,    2, 0x05,
       6,    3,   54,    2, 0x05,
      13,    1,   61,    2, 0x05,
      15,    1,   64,    2, 0x05,
      16,    1,   67,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 9, 0x80000000 | 11,    8,   10,   12,
    QMetaType::Void, QMetaType::Float,   14,
    QMetaType::Void, QMetaType::Float,   14,
    QMetaType::Void, QMetaType::Float,   14,

       0        // eod
};

void GLSatAbstractWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLSatAbstractWidget *_t = static_cast<GLSatAbstractWidget *>(_o);
        switch (_id) {
        case 0: _t->statusZRVChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->doubleClickedSat(); break;
        case 2: _t->doubleClickedLoc(); break;
        case 3: _t->currentChanged((*reinterpret_cast< Satellite*(*)>(_a[1])),(*reinterpret_cast< Location*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3]))); break;
        case 4: _t->zoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->movedX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->movedY((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GLSatAbstractWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::statusZRVChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::doubleClickedSat)) {
                *result = 1;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::doubleClickedLoc)) {
                *result = 2;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)(Satellite * , Location * , double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::currentChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::zoomed)) {
                *result = 4;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::movedX)) {
                *result = 5;
            }
        }
        {
            typedef void (GLSatAbstractWidget::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLSatAbstractWidget::movedY)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject GLSatAbstractWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLSatAbstractWidget.data,
      qt_meta_data_GLSatAbstractWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *GLSatAbstractWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLSatAbstractWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatAbstractWidget.stringdata))
        return static_cast<void*>(const_cast< GLSatAbstractWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLSatAbstractWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GLSatAbstractWidget::statusZRVChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLSatAbstractWidget::doubleClickedSat()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GLSatAbstractWidget::doubleClickedLoc()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GLSatAbstractWidget::currentChanged(Satellite * _t1, Location * _t2, double * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GLSatAbstractWidget::zoomed(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLSatAbstractWidget::movedX(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GLSatAbstractWidget::movedY(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
