/****************************************************************************
** Meta object code from reading C++ file 'SSatDialog.h'
**
** Created: Fri 15. Jun 11:33:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SSatDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SSatDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SSatDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
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
      85,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     117,  111,   11,   11, 0x08,
     134,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SSatDialog[] = {
    "SSatDialog\0\0setColorSatName()\0"
    "setColorSatZrv()\0setColorSatLines()\0"
    "setColorSatTrack()\0setSatFont()\0"
    "setDefault()\0index\0selectModel(int)\0"
    "setIcon()\0"
};

void SSatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SSatDialog *_t = static_cast<SSatDialog *>(_o);
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

const QMetaObjectExtraData SSatDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SSatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SSatDialog,
      qt_meta_data_SSatDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SSatDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SSatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SSatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SSatDialog))
        return static_cast<void*>(const_cast< SSatDialog*>(this));
    if (!strcmp(_clname, "Ui::SatDialog"))
        return static_cast< Ui::SatDialog*>(const_cast< SSatDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SSatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
