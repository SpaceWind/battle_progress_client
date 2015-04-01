/****************************************************************************
** Meta object code from reading C++ file 'gameserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/system/gameserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameServer_t {
    QByteArrayData data[7];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameServer_t qt_meta_stringdata_GameServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameServer"
QT_MOC_LITERAL(1, 11, 12), // "callFinished"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "result"
QT_MOC_LITERAL(4, 32, 13), // "replyFinished"
QT_MOC_LITERAL(5, 46, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 61, 5) // "reply"

    },
    "GameServer\0callFinished\0\0result\0"
    "replyFinished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void GameServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameServer *_t = static_cast<GameServer *>(_o);
        switch (_id) {
        case 0: _t->callFinished((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameServer::callFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GameServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameServer.data,
      qt_meta_data_GameServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GameServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GameServer.stringdata))
        return static_cast<void*>(const_cast< GameServer*>(this));
    return QObject::qt_metacast(_clname);
}

int GameServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameServer::callFinished(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ActionResponser_t {
    QByteArrayData data[4];
    char stringdata[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActionResponser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActionResponser_t qt_meta_stringdata_ActionResponser = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ActionResponser"
QT_MOC_LITERAL(1, 16, 15), // "processResponse"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6) // "result"

    },
    "ActionResponser\0processResponse\0\0"
    "result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActionResponser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

       0        // eod
};

void ActionResponser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ActionResponser *_t = static_cast<ActionResponser *>(_o);
        switch (_id) {
        case 0: _t->processResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ActionResponser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ActionResponser.data,
      qt_meta_data_ActionResponser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ActionResponser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActionResponser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ActionResponser.stringdata))
        return static_cast<void*>(const_cast< ActionResponser*>(this));
    return QObject::qt_metacast(_clname);
}

int ActionResponser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_ActionPerformer_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ActionPerformer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ActionPerformer_t qt_meta_stringdata_ActionPerformer = {
    {
QT_MOC_LITERAL(0, 0, 15) // "ActionPerformer"

    },
    "ActionPerformer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ActionPerformer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ActionPerformer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ActionPerformer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ActionPerformer.data,
      qt_meta_data_ActionPerformer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ActionPerformer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ActionPerformer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ActionPerformer.stringdata))
        return static_cast<void*>(const_cast< ActionPerformer*>(this));
    return QObject::qt_metacast(_clname);
}

int ActionPerformer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
