/****************************************************************************
** Meta object code from reading C++ file 'SWindow.h'
**
** Created: Sat 25. Aug 13:48:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      22,    8,    8,    8, 0x08,
      44,   38,    8,    8, 0x08,
      72,   67,    8,    8, 0x08,
     103,   95,    8,    8, 0x08,
     122,    8,    8,    8, 0x08,
     132,    8,    8,    8, 0x08,
     146,    8,    8,    8, 0x08,
     160,    8,    8,    8, 0x08,
     178,    8,    8,    8, 0x08,
     201,  195,    8,    8, 0x08,
     220,  195,    8,    8, 0x08,
     240,  195,    8,    8, 0x08,
     273,  260,    8,    8, 0x08,
     314,  195,    8,    8, 0x08,
     331,  195,    8,    8, 0x08,
     351,  195,    8,    8, 0x08,
     371,    8,    8,    8, 0x08,
     394,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SWindow[] = {
    "SWindow\0\0fullScreen()\0escFullScreen()\0"
    "index\0onTimeTypeChanged(int)\0text\0"
    "addZRVMessage(QString)\0checked\0"
    "checkVersion(bool)\0onTimer()\0onPlayClick()\0"
    "onTimeClick()\0onBackwardClick()\0"
    "onForwardClick()\0value\0onStepChanged(int)\0"
    "onTimeXChanged(int)\0selectLanguage(int)\0"
    "sat,loc,time\0setSwlVars(Satellite*,Location*,double*)\0"
    "selectStyle(int)\0selectGlWidget(int)\0"
    "selectPalette(bool)\0onBtnPrintScrClicked()\0"
    "resetSettings()\0"
};

void SWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SWindow *_t = static_cast<SWindow *>(_o);
        switch (_id) {
        case 0: _t->fullScreen(); break;
        case 1: _t->escFullScreen(); break;
        case 2: _t->onTimeTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addZRVMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->checkVersion((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onTimer(); break;
        case 6: _t->onPlayClick(); break;
        case 7: _t->onTimeClick(); break;
        case 8: _t->onBackwardClick(); break;
        case 9: _t->onForwardClick(); break;
        case 10: _t->onStepChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->onTimeXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->selectLanguage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setSwlVars((*reinterpret_cast< Satellite*(*)>(_a[1])),(*reinterpret_cast< Location*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3]))); break;
        case 14: _t->selectStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->selectGlWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->selectPalette((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->onBtnPrintScrClicked(); break;
        case 18: _t->resetSettings(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SWindow,
      qt_meta_data_SWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SWindow))
        return static_cast<void*>(const_cast< SWindow*>(this));
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(const_cast< SWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
