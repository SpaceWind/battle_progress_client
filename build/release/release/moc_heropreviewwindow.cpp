/****************************************************************************
** Meta object code from reading C++ file 'heropreviewwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/views/heropreviewwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'heropreviewwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loadFullHeroInfoResponser_t {
    QByteArrayData data[4];
    char stringdata[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_loadFullHeroInfoResponser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_loadFullHeroInfoResponser_t qt_meta_stringdata_loadFullHeroInfoResponser = {
    {
QT_MOC_LITERAL(0, 0, 25), // "loadFullHeroInfoResponser"
QT_MOC_LITERAL(1, 26, 15), // "processResponse"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 8) // "response"

    },
    "loadFullHeroInfoResponser\0processResponse\0"
    "\0response"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loadFullHeroInfoResponser[] = {

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

void loadFullHeroInfoResponser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loadFullHeroInfoResponser *_t = static_cast<loadFullHeroInfoResponser *>(_o);
        switch (_id) {
        case 0: _t->processResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject loadFullHeroInfoResponser::staticMetaObject = {
    { &ActionResponser::staticMetaObject, qt_meta_stringdata_loadFullHeroInfoResponser.data,
      qt_meta_data_loadFullHeroInfoResponser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *loadFullHeroInfoResponser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loadFullHeroInfoResponser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_loadFullHeroInfoResponser.stringdata))
        return static_cast<void*>(const_cast< loadFullHeroInfoResponser*>(this));
    return ActionResponser::qt_metacast(_clname);
}

int loadFullHeroInfoResponser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ActionResponser::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_heroPreviewWindow_t {
    QByteArrayData data[7];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_heroPreviewWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_heroPreviewWindow_t qt_meta_stringdata_heroPreviewWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "heroPreviewWindow"
QT_MOC_LITERAL(1, 18, 13), // "useHeroAction"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "useHeroResponse"
QT_MOC_LITERAL(4, 49, 8), // "response"
QT_MOC_LITERAL(5, 58, 22), // "loadFullHeroInfoAction"
QT_MOC_LITERAL(6, 81, 24) // "loadFullHeroInfoResponse"

    },
    "heroPreviewWindow\0useHeroAction\0\0"
    "useHeroResponse\0response\0"
    "loadFullHeroInfoAction\0loadFullHeroInfoResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_heroPreviewWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,

       0        // eod
};

void heroPreviewWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        heroPreviewWindow *_t = static_cast<heroPreviewWindow *>(_o);
        switch (_id) {
        case 0: _t->useHeroAction(); break;
        case 1: _t->useHeroResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->loadFullHeroInfoAction(); break;
        case 3: _t->loadFullHeroInfoResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject heroPreviewWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_heroPreviewWindow.data,
      qt_meta_data_heroPreviewWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *heroPreviewWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *heroPreviewWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_heroPreviewWindow.stringdata))
        return static_cast<void*>(const_cast< heroPreviewWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int heroPreviewWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
