/****************************************************************************
** Meta object code from reading C++ file 'SWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jswidgets/SWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SWidget_t {
    QByteArrayData data[21];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SWidget_t qt_meta_stringdata_SWidget = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 8),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 1),
QT_MOC_LITERAL(4, 20, 1),
QT_MOC_LITERAL(5, 22, 4),
QT_MOC_LITERAL(6, 27, 4),
QT_MOC_LITERAL(7, 32, 5),
QT_MOC_LITERAL(8, 38, 6),
QT_MOC_LITERAL(9, 45, 7),
QT_MOC_LITERAL(10, 53, 4),
QT_MOC_LITERAL(11, 58, 9),
QT_MOC_LITERAL(12, 68, 6),
QT_MOC_LITERAL(13, 75, 6),
QT_MOC_LITERAL(14, 82, 7),
QT_MOC_LITERAL(15, 90, 1),
QT_MOC_LITERAL(16, 92, 1),
QT_MOC_LITERAL(17, 94, 6),
QT_MOC_LITERAL(18, 101, 11),
QT_MOC_LITERAL(19, 113, 12),
QT_MOC_LITERAL(20, 126, 7)
    },
    "SWidget\0drawText\0\0x\0y\0text\0fill\0value\0"
    "setPen\0setFont\0name\0pointSize\0weight\0"
    "italic\0setSize\0w\0h\0setPos\0setInterval\0"
    "setMaskColor\0onTimer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SWidget[] = {

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
       1,    3,   59,    2, 0x0a,
       6,    1,   66,    2, 0x0a,
       8,    1,   69,    2, 0x0a,
       9,    4,   72,    2, 0x0a,
      14,    2,   81,    2, 0x0a,
      17,    2,   86,    2, 0x0a,
      18,    1,   91,    2, 0x0a,
      19,    1,   94,    2, 0x0a,
      20,    0,   97,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   10,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void SWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SWidget *_t = static_cast<SWidget *>(_o);
        switch (_id) {
        case 0: _t->drawText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->fill((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setPen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setFont((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->setSize((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->setInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setMaskColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onTimer(); break;
        default: ;
        }
    }
}

const QMetaObject SWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SWidget.data,
      qt_meta_data_SWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *SWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SWidget.stringdata))
        return static_cast<void*>(const_cast< SWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
