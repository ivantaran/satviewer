/****************************************************************************
** Meta object code from reading C++ file 'SObjDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SObjDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SObjDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SObjDialog_t {
    QByteArrayData data[11];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SObjDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SObjDialog_t qt_meta_stringdata_SObjDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 14),
QT_MOC_LITERAL(4, 43, 16),
QT_MOC_LITERAL(5, 60, 16),
QT_MOC_LITERAL(6, 77, 10),
QT_MOC_LITERAL(7, 88, 10),
QT_MOC_LITERAL(8, 99, 11),
QT_MOC_LITERAL(9, 111, 5),
QT_MOC_LITERAL(10, 117, 7)
    },
    "SObjDialog\0setColorSatName\0\0setColorSatZrv\0"
    "setColorSatLines\0setColorSatTrack\0"
    "setSatFont\0setDefault\0selectModel\0"
    "index\0setIcon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SObjDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    1,   60,    2, 0x08,
      10,    0,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void SObjDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SObjDialog *_t = static_cast<SObjDialog *>(_o);
        switch (_id) {
        case 0: _t->setColorSatName(); break;
        case 1: _t->setColorSatZrv(); break;
        case 2: _t->setColorSatLines(); break;
        case 3: _t->setColorSatTrack(); break;
        case 4: _t->setSatFont(); break;
        case 5: _t->setDefault(); break;
        case 6: _t->selectModel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setIcon(); break;
        default: ;
        }
    }
}

const QMetaObject SObjDialog::staticMetaObject = {
    { &SAbstractObjDialog::staticMetaObject, qt_meta_stringdata_SObjDialog.data,
      qt_meta_data_SObjDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SObjDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SObjDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SObjDialog.stringdata))
        return static_cast<void*>(const_cast< SObjDialog*>(this));
    if (!strcmp(_clname, "Ui::SatDialog"))
        return static_cast< Ui::SatDialog*>(const_cast< SObjDialog*>(this));
    return SAbstractObjDialog::qt_metacast(_clname);
}

int SObjDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SAbstractObjDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
