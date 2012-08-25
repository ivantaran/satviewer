/****************************************************************************
** Meta object code from reading C++ file 'SDlgOptions.h'
**
** Created: Sat 25. Aug 13:48:23 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SDlgOptions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SDlgOptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SDlgOptions[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,
      38,   12,   12,   12, 0x08,
      54,   12,   12,   12, 0x08,
      69,   12,   12,   12, 0x08,
     102,   85,   12,   12, 0x08,
     138,   12,   12,   12, 0x08,
     154,   12,   12,   12, 0x08,
     170,   12,   12,   12, 0x08,
     186,   12,   12,   12, 0x08,
     205,   12,   12,   12, 0x08,
     226,   12,   12,   12, 0x08,
     242,   12,   12,   12, 0x08,
     262,   12,   12,   12, 0x08,
     278,   12,   12,   12, 0x08,
     296,   85,   12,   12, 0x08,
     333,   85,   12,   12, 0x08,
     370,   85,   12,   12, 0x08,
     405,   85,   12,   12, 0x08,
     440,   12,   12,   12, 0x08,
     455,   12,   12,   12, 0x08,
     475,  470,   12,   12, 0x08,
     501,  470,   12,   12, 0x08,
     527,   12,   12,   12, 0x08,
     542,   12,   12,   12, 0x08,
     557,   12,   12,   12, 0x08,
     573,   12,   12,   12, 0x08,
     584,   12,   12,   12, 0x08,
     596,   12,   12,   12, 0x08,
     609,   12,   12,   12, 0x08,
     622,   12,   12,   12, 0x08,
     636,   12,   12,   12, 0x08,
     656,  650,   12,   12, 0x08,
     682,  650,   12,   12, 0x08,
     708,  650,   12,   12, 0x08,
     736,  650,   12,   12, 0x08,
     764,   12,   12,   12, 0x08,
     783,   12,   12,   12, 0x08,
     797,   12,   12,   12, 0x08,
     811,   12,   12,   12, 0x08,
     824,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SDlgOptions[] = {
    "SDlgOptions\0\0aboutQt()\0addToSatList()\0"
    "deleteSatList()\0addToLocList()\0"
    "deleteLocList()\0current,previous\0"
    "selectPage(QModelIndex,QModelIndex)\0"
    "selectSatPage()\0selectLocPage()\0"
    "selectZrvPage()\0selectParamsPage()\0"
    "selectSettingsPage()\0selectTlePage()\0"
    "selectWidgetsPage()\0selectMapPage()\0"
    "selectAboutPage()\0"
    "selectDbSat(QModelIndex,QModelIndex)\0"
    "selectDbLoc(QModelIndex,QModelIndex)\0"
    "selectSat(QModelIndex,QModelIndex)\0"
    "selectLoc(QModelIndex,QModelIndex)\0"
    "clearSatList()\0clearLocList()\0line\0"
    "setFilterSatName(QString)\0"
    "setFilterLocName(QString)\0setFilterSat()\0"
    "setFilterLoc()\0loadDbFromTle()\0"
    "addDbLoc()\0loadDbLoc()\0clearDbSat()\0"
    "clearDbLoc()\0deleteDbSat()\0deleteDbLoc()\0"
    "index\0addToSatList(QModelIndex)\0"
    "addToLocList(QModelIndex)\0"
    "delFromSatList(QModelIndex)\0"
    "delFromLocList(QModelIndex)\0"
    "scriptParameters()\0changeDbSat()\0"
    "changeDbLoc()\0helpSatSql()\0helpLocSql()\0"
};

void SDlgOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SDlgOptions *_t = static_cast<SDlgOptions *>(_o);
        switch (_id) {
        case 0: _t->aboutQt(); break;
        case 1: _t->addToSatList(); break;
        case 2: _t->deleteSatList(); break;
        case 3: _t->addToLocList(); break;
        case 4: _t->deleteLocList(); break;
        case 5: _t->selectPage((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 6: _t->selectSatPage(); break;
        case 7: _t->selectLocPage(); break;
        case 8: _t->selectZrvPage(); break;
        case 9: _t->selectParamsPage(); break;
        case 10: _t->selectSettingsPage(); break;
        case 11: _t->selectTlePage(); break;
        case 12: _t->selectWidgetsPage(); break;
        case 13: _t->selectMapPage(); break;
        case 14: _t->selectAboutPage(); break;
        case 15: _t->selectDbSat((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 16: _t->selectDbLoc((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 17: _t->selectSat((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 18: _t->selectLoc((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 19: _t->clearSatList(); break;
        case 20: _t->clearLocList(); break;
        case 21: _t->setFilterSatName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->setFilterLocName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->setFilterSat(); break;
        case 24: _t->setFilterLoc(); break;
        case 25: _t->loadDbFromTle(); break;
        case 26: _t->addDbLoc(); break;
        case 27: _t->loadDbLoc(); break;
        case 28: _t->clearDbSat(); break;
        case 29: _t->clearDbLoc(); break;
        case 30: _t->deleteDbSat(); break;
        case 31: _t->deleteDbLoc(); break;
        case 32: _t->addToSatList((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 33: _t->addToLocList((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 34: _t->delFromSatList((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 35: _t->delFromLocList((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 36: _t->scriptParameters(); break;
        case 37: _t->changeDbSat(); break;
        case 38: _t->changeDbLoc(); break;
        case 39: _t->helpSatSql(); break;
        case 40: _t->helpLocSql(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SDlgOptions::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SDlgOptions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SDlgOptions,
      qt_meta_data_SDlgOptions, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SDlgOptions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SDlgOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SDlgOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SDlgOptions))
        return static_cast<void*>(const_cast< SDlgOptions*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< SDlgOptions*>(this));
    return QDialog::qt_metacast(_clname);
}

int SDlgOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
