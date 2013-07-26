/****************************************************************************
** Meta object code from reading C++ file 'SWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SWindow_t {
    QByteArrayData data[31];
    char stringdata[341];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SWindow_t qt_meta_stringdata_SWindow = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 10),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 13),
QT_MOC_LITERAL(4, 34, 17),
QT_MOC_LITERAL(5, 52, 5),
QT_MOC_LITERAL(6, 58, 13),
QT_MOC_LITERAL(7, 72, 4),
QT_MOC_LITERAL(8, 77, 12),
QT_MOC_LITERAL(9, 90, 7),
QT_MOC_LITERAL(10, 98, 7),
QT_MOC_LITERAL(11, 106, 11),
QT_MOC_LITERAL(12, 118, 11),
QT_MOC_LITERAL(13, 130, 15),
QT_MOC_LITERAL(14, 146, 14),
QT_MOC_LITERAL(15, 161, 13),
QT_MOC_LITERAL(16, 175, 5),
QT_MOC_LITERAL(17, 181, 14),
QT_MOC_LITERAL(18, 196, 14),
QT_MOC_LITERAL(19, 211, 10),
QT_MOC_LITERAL(20, 222, 10),
QT_MOC_LITERAL(21, 233, 3),
QT_MOC_LITERAL(22, 237, 9),
QT_MOC_LITERAL(23, 247, 3),
QT_MOC_LITERAL(24, 251, 7),
QT_MOC_LITERAL(25, 259, 4),
QT_MOC_LITERAL(26, 264, 11),
QT_MOC_LITERAL(27, 276, 14),
QT_MOC_LITERAL(28, 291, 13),
QT_MOC_LITERAL(29, 305, 20),
QT_MOC_LITERAL(30, 326, 13)
    },
    "SWindow\0fullScreen\0\0escFullScreen\0"
    "onTimeTypeChanged\0index\0addZRVMessage\0"
    "text\0checkVersion\0checked\0onTimer\0"
    "onPlayClick\0onTimeClick\0onBackwardClick\0"
    "onForwardClick\0onStepChanged\0value\0"
    "onTimeXChanged\0selectLanguage\0setSwlVars\0"
    "Satellite*\0sat\0Location*\0loc\0double*\0"
    "time\0selectStyle\0selectGlWidget\0"
    "selectPalette\0onBtnPrintScrClicked\0"
    "resetSettings\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08,
       3,    0,  110,    2, 0x08,
       4,    1,  111,    2, 0x08,
       6,    1,  114,    2, 0x08,
       8,    1,  117,    2, 0x08,
      10,    0,  120,    2, 0x08,
      11,    0,  121,    2, 0x08,
      12,    0,  122,    2, 0x08,
      13,    0,  123,    2, 0x08,
      14,    0,  124,    2, 0x08,
      15,    1,  125,    2, 0x08,
      17,    1,  128,    2, 0x08,
      18,    1,  131,    2, 0x08,
      19,    3,  134,    2, 0x08,
      26,    1,  141,    2, 0x08,
      27,    1,  144,    2, 0x08,
      28,    1,  147,    2, 0x08,
      29,    0,  150,    2, 0x08,
      30,    0,  151,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22, 0x80000000 | 24,   21,   23,   25,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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

const QMetaObject SWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SWindow.data,
      qt_meta_data_SWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *SWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SWindow.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
