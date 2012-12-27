/****************************************************************************
** Meta object code from reading C++ file 'MapController.h'
**
** Created: Thu Dec 27 11:02:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/controllers/MapController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MapController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MapController[] = {

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

 // methods: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x02,
      44,   14,   14,   14, 0x02,
      53,   14,   14,   14, 0x02,
      73,   63,   14,   14, 0x02,
     104,   91,   14,   14, 0x02,
     142,  132,   14,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_MapController[] = {
    "MapController\0\0webView\0setWebView(QObject*)\0"
    "zoomIn()\0zoomOut()\0zoomLevel\0"
    "setZoomLevel(int)\0pins,mapType\0"
    "setMapPins(QVariantMap,int)\0clickable\0"
    "setPinsClickable(bool)\0"
};

void MapController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MapController *_t = static_cast<MapController *>(_o);
        switch (_id) {
        case 0: _t->setWebView((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->zoomIn(); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->setZoomLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setMapPins((*reinterpret_cast< QVariantMap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setPinsClickable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MapController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MapController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MapController,
      qt_meta_data_MapController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MapController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MapController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MapController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MapController))
        return static_cast<void*>(const_cast< MapController*>(this));
    return QObject::qt_metacast(_clname);
}

int MapController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
