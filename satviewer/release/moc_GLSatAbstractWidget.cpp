/****************************************************************************
** Meta object code from reading C++ file 'GLSatAbstractWidget.h'
**
** Created: Fri 15. Jun 11:34:08 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ogl/GLSatAbstractWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLSatAbstractWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLSatAbstractWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x05,
      52,   20,   20,   20, 0x05,
      71,   20,   20,   20, 0x05,
     103,   90,   20,   20, 0x05,
     154,  148,   20,   20, 0x05,
     168,  148,   20,   20, 0x05,
     182,  148,   20,   20, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GLSatAbstractWidget[] = {
    "GLSatAbstractWidget\0\0text\0"
    "statusZRVChanged(QString)\0doubleClickedSat()\0"
    "doubleClickedLoc()\0sat,loc,time\0"
    "currentChanged(Satellite*,Location*,double*)\0"
    "value\0zoomed(float)\0movedX(float)\0"
    "movedY(float)\0"
};

void GLSatAbstractWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GLSatAbstractWidget *_t = static_cast<GLSatAbstractWidget *>(_o);
        switch (_id) {
        case 0: _t->statusZRVChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->doubleClickedSat(); break;
        case 2: _t->doubleClickedLoc(); break;
        case 3: _t->currentChanged((*reinterpret_cast< Satellite*(*)>(_a[1])),(*reinterpret_cast< Location*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3]))); break;
        case 4: _t->zoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->movedX((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->movedY((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GLSatAbstractWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GLSatAbstractWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLSatAbstractWidget,
      qt_meta_data_GLSatAbstractWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLSatAbstractWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLSatAbstractWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLSatAbstractWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLSatAbstractWidget))
        return static_cast<void*>(const_cast< GLSatAbstractWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLSatAbstractWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GLSatAbstractWidget::statusZRVChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GLSatAbstractWidget::doubleClickedSat()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GLSatAbstractWidget::doubleClickedLoc()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GLSatAbstractWidget::currentChanged(Satellite * _t1, Location * _t2, double * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GLSatAbstractWidget::zoomed(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GLSatAbstractWidget::movedX(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GLSatAbstractWidget::movedY(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
