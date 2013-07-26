/****************************************************************************
** Meta object code from reading C++ file 'SLocDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SLocDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SLocDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SLocDialog_t {
    QByteArrayData data[8];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SLocDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SLocDialog_t qt_meta_stringdata_SLocDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 14),
QT_MOC_LITERAL(4, 43, 16),
QT_MOC_LITERAL(5, 60, 10),
QT_MOC_LITERAL(6, 71, 10),
QT_MOC_LITERAL(7, 82, 7)
    },
    "SLocDialog\0setColorLocName\0\0setColorLocZrv\0"
    "setColorLocLines\0setLocFont\0setDefault\0"
    "setIcon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SLocDialog[] = {

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
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    0,   47,    2, 0x08,
       6,    0,   48,    2, 0x08,
       7,    0,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SLocDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SLocDialog *_t = static_cast<SLocDialog *>(_o);
        switch (_id) {
        case 0: _t->setColorLocName(); break;
        case 1: _t->setColorLocZrv(); break;
        case 2: _t->setColorLocLines(); break;
        case 3: _t->setLocFont(); break;
        case 4: _t->setDefault(); break;
        case 5: _t->setIcon(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SLocDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SLocDialog.data,
      qt_meta_data_SLocDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SLocDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SLocDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SLocDialog.stringdata))
        return static_cast<void*>(const_cast< SLocDialog*>(this));
    if (!strcmp(_clname, "Ui::LocDialog"))
        return static_cast< Ui::LocDialog*>(const_cast< SLocDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SLocDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
