/****************************************************************************
** Meta object code from reading C++ file 'GLSatWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ogl/GLSatWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLSatWidget_t {
    QByteArrayData data[13];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GLSatWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GLSatWidget_t qt_meta_stringdata_GLSatWidget = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 19),
QT_MOC_LITERAL(4, 49, 17),
QT_MOC_LITERAL(5, 67, 18),
QT_MOC_LITERAL(6, 86, 5),
QT_MOC_LITERAL(7, 92, 10),
QT_MOC_LITERAL(8, 103, 5),
QT_MOC_LITERAL(9, 109, 12),
QT_MOC_LITERAL(10, 122, 10),
QT_MOC_LITERAL(11, 133, 7),
QT_MOC_LITERAL(12, 141, 7)
    },
    "GLSatWidget\0btnColorClicked\0\0"
    "onBtnMapFileClicked\0btnFontNetClicked\0"
    "onColorTypeChanged\0index\0onCheckSun\0"
    "value\0onCheckNight\0changeZoom\0changeX\0"
    "changeY\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLSatWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    1,   62,    2, 0x08,
       7,    1,   65,    2, 0x08,
       9,    1,   68,    2, 0x08,
      10,    1,   71,    2, 0x08,
      11,    1,   74,    2, 0x08,
      12,    1,   77,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void GLSatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLSatWidget *_t = static_cast<GLSatWidget *>(_o);
        switch (_id) {
        case 0: _t->btnColorClicked(); break;
        case 1: _t->onBtnMapFileClicked(); break;
        case 2: _t->btnFontNetClicked(); break;
        case 3: _t->onColorTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onCheckSun((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onCheckNight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->changeZoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->changeX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->changeY((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GLSatWidget::staticMetaObject = {
    { &GLSatAbstractWidget::staticMetaObject, qt_meta_stringdata_GLSatWidget.data,
      qt_meta_data_GLSatWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *GLSatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLSatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatWidget.stringdata))
        return static_cast<void*>(const_cast< GLSatWidget*>(this));
    return GLSatAbstractWidget::qt_metacast(_clname);
}

int GLSatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLSatAbstractWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
