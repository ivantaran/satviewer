/****************************************************************************
** Meta object code from reading C++ file 'UCheck.h'
**
** Created: Fri 15. Jun 11:34:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uchecker/UCheck.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UCheck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UCheck[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UCheck[] = {
    "UCheck\0\0error\0verify(bool)\0"
};

void UCheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UCheck *_t = static_cast<UCheck *>(_o);
        switch (_id) {
        case 0: _t->verify((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UCheck::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UCheck::staticMetaObject = {
    { &QHttp::staticMetaObject, qt_meta_stringdata_UCheck,
      qt_meta_data_UCheck, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UCheck::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UCheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UCheck::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UCheck))
        return static_cast<void*>(const_cast< UCheck*>(this));
    return QHttp::qt_metacast(_clname);
}

int UCheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHttp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
