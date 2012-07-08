/****************************************************************************
** Meta object code from reading C++ file 'SWidget.h'
**
** Created: Fri 15. Jun 11:34:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../jswidgets/SWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SWidget[] = {

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
      18,    9,    8,    8, 0x0a,
      50,   44,    8,    8, 0x0a,
      60,   44,    8,    8, 0x0a,
     101,   72,    8,    8, 0x0a,
     135,  131,    8,    8, 0x0a,
     156,  152,    8,    8, 0x0a,
     172,   44,    8,    8, 0x0a,
     189,   44,    8,    8, 0x0a,
     207,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SWidget[] = {
    "SWidget\0\0x,y,text\0drawText(int,int,QString)\0"
    "value\0fill(int)\0setPen(int)\0"
    "name,pointSize,weight,italic\0"
    "setFont(QString,int,int,bool)\0w,h\0"
    "setSize(int,int)\0x,y\0setPos(int,int)\0"
    "setInterval(int)\0setMaskColor(int)\0"
    "onTimer()\0"
};

void SWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData SWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SWidget,
      qt_meta_data_SWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SWidget))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
