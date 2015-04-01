/****************************************************************************
** Meta object code from reading C++ file 'newherodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/views/newherodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newherodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_newHeroDialog_t {
    QByteArrayData data[15];
    char stringdata[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_newHeroDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_newHeroDialog_t qt_meta_stringdata_newHeroDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "newHeroDialog"
QT_MOC_LITERAL(1, 14, 17), // "getFactionsAction"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "getFactionsResponse"
QT_MOC_LITERAL(4, 53, 8), // "response"
QT_MOC_LITERAL(5, 62, 16), // "getClassesAction"
QT_MOC_LITERAL(6, 79, 18), // "getClassesResponse"
QT_MOC_LITERAL(7, 98, 14), // "rollHeroAction"
QT_MOC_LITERAL(8, 113, 16), // "rollHeroResponse"
QT_MOC_LITERAL(9, 130, 21), // "saveRolledChampAction"
QT_MOC_LITERAL(10, 152, 23), // "saveRolledChampResponse"
QT_MOC_LITERAL(11, 176, 24), // "on_hero_name_textChanged"
QT_MOC_LITERAL(12, 201, 4), // "arg1"
QT_MOC_LITERAL(13, 206, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 228, 21) // "on_saveButton_clicked"

    },
    "newHeroDialog\0getFactionsAction\0\0"
    "getFactionsResponse\0response\0"
    "getClassesAction\0getClassesResponse\0"
    "rollHeroAction\0rollHeroResponse\0"
    "saveRolledChampAction\0saveRolledChampResponse\0"
    "on_hero_name_textChanged\0arg1\0"
    "on_pushButton_clicked\0on_saveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_newHeroDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    1,   70,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    1,   74,    2, 0x0a /* Public */,
       7,    0,   77,    2, 0x0a /* Public */,
       8,    1,   78,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      11,    1,   85,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void newHeroDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        newHeroDialog *_t = static_cast<newHeroDialog *>(_o);
        switch (_id) {
        case 0: _t->getFactionsAction(); break;
        case 1: _t->getFactionsResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->getClassesAction(); break;
        case 3: _t->getClassesResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->rollHeroAction(); break;
        case 5: _t->rollHeroResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->saveRolledChampAction(); break;
        case 7: _t->saveRolledChampResponse((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->on_hero_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject newHeroDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_newHeroDialog.data,
      qt_meta_data_newHeroDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *newHeroDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *newHeroDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_newHeroDialog.stringdata))
        return static_cast<void*>(const_cast< newHeroDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int newHeroDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
