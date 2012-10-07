/****************************************************************************
** Meta object code from reading C++ file 'SLocDialog.h'
**
** Created: Sun 7. Oct 19:14:34 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SLocDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SLocDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SLocDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SLocDialog[] = {
    "SLocDialog\0\0setColorLocName()\0"
    "setColorLocZrv()\0setColorLocLines()\0"
    "setLocFont()\0setDefault()\0setIcon()\0"
};

void SLocDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData SLocDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SLocDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SLocDialog,
      qt_meta_data_SLocDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SLocDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SLocDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SLocDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SLocDialog))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
