/****************************************************************************
** Meta object code from reading C++ file 'SUpdater.h'
**
** Created: Sun 8. Jul 19:54:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tleupd/SUpdater.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SUpdater[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      43,   22,    9,    9, 0x08,
      90,   75,    9,    9, 0x08,
     136,  130,    9,    9, 0x08,
     150,    9,    9,    9, 0x08,
     157,    9,    9,    9, 0x08,
     167,    9,    9,    9, 0x08,
     180,    9,    9,    9, 0x08,
     188,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SUpdater[] = {
    "SUpdater\0\0updateTle()\0bytesRead,totalBytes\0"
    "updateDataReadProgress(int,int)\0"
    "responseHeader\0readResponseHeader(QHttpResponseHeader)\0"
    "error\0doneGet(bool)\0save()\0addLine()\0"
    "removeLine()\0clear()\0abort()\0"
};

void SUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SUpdater *_t = static_cast<SUpdater *>(_o);
        switch (_id) {
        case 0: _t->updateTle(); break;
        case 1: _t->updateDataReadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->readResponseHeader((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 3: _t->doneGet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->save(); break;
        case 5: _t->addLine(); break;
        case 6: _t->removeLine(); break;
        case 7: _t->clear(); break;
        case 8: _t->abort(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SUpdater::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SUpdater::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SUpdater,
      qt_meta_data_SUpdater, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SUpdater::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SUpdater))
        return static_cast<void*>(const_cast< SUpdater*>(this));
    if (!strcmp(_clname, "Ui::Updater"))
        return static_cast< Ui::Updater*>(const_cast< SUpdater*>(this));
    return QWidget::qt_metacast(_clname);
}

int SUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
