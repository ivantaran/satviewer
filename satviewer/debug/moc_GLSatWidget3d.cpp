/****************************************************************************
** Meta object code from reading C++ file 'GLSatWidget3d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ogl/GLSatWidget3d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatWidget3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLSatWidget3d_t {
    QByteArrayData data[9];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GLSatWidget3d_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GLSatWidget3d_t qt_meta_stringdata_GLSatWidget3d = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 5),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 5),
QT_MOC_LITERAL(4, 27, 5),
QT_MOC_LITERAL(5, 33, 7),
QT_MOC_LITERAL(6, 41, 7),
QT_MOC_LITERAL(7, 49, 7),
QT_MOC_LITERAL(8, 57, 4)
    },
    "GLSatWidget3d\0moveX\0\0value\0moveY\0"
    "rotateX\0rotateY\0rotateZ\0zoom\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLSatWidget3d[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08,
       4,    1,   47,    2, 0x08,
       5,    1,   50,    2, 0x08,
       6,    1,   53,    2, 0x08,
       7,    1,   56,    2, 0x08,
       8,    1,   59,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,

       0        // eod
};

void GLSatWidget3d::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLSatWidget3d *_t = static_cast<GLSatWidget3d *>(_o);
        switch (_id) {
        case 0: _t->moveX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->moveY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->rotateX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->rotateY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->rotateZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->zoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GLSatWidget3d::staticMetaObject = {
    { &GLSatAbstractWidget::staticMetaObject, qt_meta_stringdata_GLSatWidget3d.data,
      qt_meta_data_GLSatWidget3d,  qt_static_metacall, 0, 0}
};


const QMetaObject *GLSatWidget3d::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLSatWidget3d::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatWidget3d.stringdata))
        return static_cast<void*>(const_cast< GLSatWidget3d*>(this));
    return GLSatAbstractWidget::qt_metacast(_clname);
}

int GLSatWidget3d::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLSatAbstractWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
