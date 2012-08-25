/****************************************************************************
** Meta object code from reading C++ file 'GLSatWidget.h'
**
** Created: Sat 25. Aug 13:48:56 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ogl/GLSatWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLSatWidget[] = {

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
      13,   12,   12,   12, 0x08,
      31,   12,   12,   12, 0x08,
      53,   12,   12,   12, 0x08,
      79,   73,   12,   12, 0x08,
     109,  103,   12,   12, 0x08,
     126,  103,   12,   12, 0x08,
     145,  103,   12,   12, 0x08,
     164,  103,   12,   12, 0x08,
     180,  103,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GLSatWidget[] = {
    "GLSatWidget\0\0btnColorClicked()\0"
    "onBtnMapFileClicked()\0btnFontNetClicked()\0"
    "index\0onColorTypeChanged(int)\0value\0"
    "onCheckSun(bool)\0onCheckNight(bool)\0"
    "changeZoom(double)\0changeX(double)\0"
    "changeY(double)\0"
};

void GLSatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData GLSatWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLSatWidget::staticMetaObject = {
    { &GLSatAbstractWidget::staticMetaObject, qt_meta_stringdata_GLSatWidget,
      qt_meta_data_GLSatWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLSatWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLSatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLSatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatWidget))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
