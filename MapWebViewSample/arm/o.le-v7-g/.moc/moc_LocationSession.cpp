/****************************************************************************
** Meta object code from reading C++ file 'LocationSession.hpp'
**
** Created: Thu Dec 27 11:02:52 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/controllers/LocationSession.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LocationSession.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LocationSession[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      22,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      31,   16,   16,   16, 0x05,
      44,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   61,   16,   16, 0x08,
      99,   16,   16,   16, 0x08,
     134,  123,   16,   16, 0x08,
     183,  123,   16,   16, 0x08,
     239,  233,   16,   16, 0x08,

 // methods: signature, parameters, type, tag, flags
     261,   16,   16,   16, 0x02,
     280,  275,   16,   16, 0x02,

 // properties: name, type, flags
     310,  302, 0x0a495001,
     324,  317, 0x06495001,
     333,  317, 0x06495001,
     343,  317, 0x06495001,
     352,  302, 0x0a495001,
     357,  302, 0x0a495001,
     367,  302, 0x0a495001,
     379,  302, 0x0a495001,
     393,  302, 0x0a495001,
     412,  302, 0x0a495001,
     429,  302, 0x0a495001,
     447,  302, 0x0a495001,
     466,  302, 0x0a495001,
     483,  302, 0x0a495001,
     500,  302, 0x0a495001,
     505,  302, 0x0a495001,
     513,  302, 0x0a495001,
     532,  527, 0x01495001,
     545,  302, 0x0a495001,
     561,  302, 0x0a495001,
     578,  302, 0x0a495001,
     611,  582, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_LocationSession[] = {
    "LocationSession\0\0dataChanged()\0"
    "logChanged()\0mapViewChanged()\0pos\0"
    "positionUpdated(QGeoPositionInfo)\0"
    "positionUpdateTimeout()\0satellites\0"
    "satellitesInUseUpdated(QList<QGeoSatelliteInfo>)\0"
    "satellitesInViewUpdated(QList<QGeoSatelliteInfo>)\0"
    "pinID\0onPinCreated(QString)\0stopUpdates()\0"
    "type\0resetSession(QString)\0QString\0"
    "method\0double\0latitude\0longitude\0"
    "altitude\0time\0direction\0groundSpeed\0"
    "verticalSpeed\0horizontalAccuracy\0"
    "verticalAccuracy\0magneticVariation\0"
    "horizontalDilution\0verticalDilution\0"
    "positionDilution\0ttff\0gpsWeek\0"
    "gpsTimeOfWeek\0bool\0isPropagated\0"
    "satellitesInUse\0satellitesInView\0log\0"
    "bb::cascades::maps::MapView*\0mapView\0"
};

void LocationSession::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LocationSession *_t = static_cast<LocationSession *>(_o);
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->logChanged(); break;
        case 2: _t->mapViewChanged(); break;
        case 3: _t->positionUpdated((*reinterpret_cast< const QGeoPositionInfo(*)>(_a[1]))); break;
        case 4: _t->positionUpdateTimeout(); break;
        case 5: _t->satellitesInUseUpdated((*reinterpret_cast< const QList<QGeoSatelliteInfo>(*)>(_a[1]))); break;
        case 6: _t->satellitesInViewUpdated((*reinterpret_cast< const QList<QGeoSatelliteInfo>(*)>(_a[1]))); break;
        case 7: _t->onPinCreated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->stopUpdates(); break;
        case 9: _t->resetSession((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LocationSession::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LocationSession::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LocationSession,
      qt_meta_data_LocationSession, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LocationSession::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LocationSession::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LocationSession::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocationSession))
        return static_cast<void*>(const_cast< LocationSession*>(this));
    return QObject::qt_metacast(_clname);
}

int LocationSession::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = method(); break;
        case 1: *reinterpret_cast< double*>(_v) = latitude(); break;
        case 2: *reinterpret_cast< double*>(_v) = longitude(); break;
        case 3: *reinterpret_cast< double*>(_v) = altitude(); break;
        case 4: *reinterpret_cast< QString*>(_v) = time(); break;
        case 5: *reinterpret_cast< QString*>(_v) = direction(); break;
        case 6: *reinterpret_cast< QString*>(_v) = groundSpeed(); break;
        case 7: *reinterpret_cast< QString*>(_v) = verticalSpeed(); break;
        case 8: *reinterpret_cast< QString*>(_v) = horizontalAccuracy(); break;
        case 9: *reinterpret_cast< QString*>(_v) = verticalAccuracy(); break;
        case 10: *reinterpret_cast< QString*>(_v) = magneticVariation(); break;
        case 11: *reinterpret_cast< QString*>(_v) = horizontalDilution(); break;
        case 12: *reinterpret_cast< QString*>(_v) = verticalDilution(); break;
        case 13: *reinterpret_cast< QString*>(_v) = positionDilution(); break;
        case 14: *reinterpret_cast< QString*>(_v) = ttff(); break;
        case 15: *reinterpret_cast< QString*>(_v) = gpsWeek(); break;
        case 16: *reinterpret_cast< QString*>(_v) = gpsTimeOfWeek(); break;
        case 17: *reinterpret_cast< bool*>(_v) = isPropagated(); break;
        case 18: *reinterpret_cast< QString*>(_v) = satellitesInUse(); break;
        case 19: *reinterpret_cast< QString*>(_v) = satellitesInView(); break;
        case 20: *reinterpret_cast< QString*>(_v) = log(); break;
        case 21: *reinterpret_cast< bb::cascades::maps::MapView**>(_v) = mapView(); break;
        }
        _id -= 22;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 21: setMapView(*reinterpret_cast< bb::cascades::maps::MapView**>(_v)); break;
        }
        _id -= 22;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 22;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 22;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void LocationSession::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LocationSession::logChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void LocationSession::mapViewChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
