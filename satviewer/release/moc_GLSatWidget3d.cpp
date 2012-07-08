/****************************************************************************
** Meta object code from reading C++ file 'GLSatWidget3d.h'
**
** Created: Fri 15. Jun 11:34:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ogl/GLSatWidget3d.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatWidget3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLSatWidget3d[] = {

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
      21,   15,   14,   14, 0x08,
      35,   15,   14,   14, 0x08,
      49,   15,   14,   14, 0x08,
      65,   15,   14,   14, 0x08,
      81,   15,   14,   14, 0x08,
      97,   15,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GLSatWidget3d[] = {
    "GLSatWidget3d\0\0value\0moveX(double)\0"
    "moveY(double)\0rotateX(double)\0"
    "rotateY(double)\0rotateZ(double)\0"
    "zoom(double)\0"
};

void GLSatWidget3d::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLSatWidget3d *_t = static_cast<GLSatWidget3d *>(_o);
        switch (_id) {
        case 0: _t->moveX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->moveY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->rotateX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->rotateY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->rotateZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->zoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLSatWidget3d::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLSatWidget3d::staticMetaObject = {
    { &GLSatAbstractWidget::staticMetaObject, qt_meta_stringdata_GLSatWidget3d,
      qt_meta_data_GLSatWidget3d, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLSatWidget3d::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLSatWidget3d::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLSatWidget3d::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatWidget3d))
        return static_cast<void*>(const_cast< GLSatWidget3d*>(this));
    return GLSatAbstractWidget::qt_metacast(_clname);
}

int GLSatWidget3d::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLSatAbstractWidget::qt_metacall(_c, _id, _a);
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
