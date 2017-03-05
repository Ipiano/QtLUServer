/****************************************************************************
** Meta object code from reading C++ file 'luauthserverhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MessageHandlers/luauthserverhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'luauthserverhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LUAuthServerHandler_t {
    QByteArrayData data[11];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LUAuthServerHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LUAuthServerHandler_t qt_meta_stringdata_LUAuthServerHandler = {
    {
QT_MOC_LITERAL(0, 0, 19), // "LUAuthServerHandler"
QT_MOC_LITERAL(1, 20, 17), // "receiveRAKMessage"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 6), // "header"
QT_MOC_LITERAL(4, 46, 11), // "SystemIndex"
QT_MOC_LITERAL(5, 58, 6), // "sysInd"
QT_MOC_LITERAL(6, 65, 13), // "SystemAddress"
QT_MOC_LITERAL(7, 79, 7), // "sysAddr"
QT_MOC_LITERAL(8, 87, 11), // "QByteArray&"
QT_MOC_LITERAL(9, 99, 4), // "data"
QT_MOC_LITERAL(10, 104, 16) // "receiveLUMessage"

    },
    "LUAuthServerHandler\0receiveRAKMessage\0"
    "\0header\0SystemIndex\0sysInd\0SystemAddress\0"
    "sysAddr\0QByteArray&\0data\0receiveLUMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LUAuthServerHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x0a /* Public */,
      10,    4,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    3,    5,    7,    9,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8,    3,    5,    7,    9,

       0        // eod
};

void LUAuthServerHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LUAuthServerHandler *_t = static_cast<LUAuthServerHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveRAKMessage((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< SystemIndex(*)>(_a[2])),(*reinterpret_cast< SystemAddress(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 1: _t->receiveLUMessage((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< SystemIndex(*)>(_a[2])),(*reinterpret_cast< SystemAddress(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject LUAuthServerHandler::staticMetaObject = {
    { &RakMessageHandler::staticMetaObject, qt_meta_stringdata_LUAuthServerHandler.data,
      qt_meta_data_LUAuthServerHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LUAuthServerHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LUAuthServerHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LUAuthServerHandler.stringdata0))
        return static_cast<void*>(const_cast< LUAuthServerHandler*>(this));
    return RakMessageHandler::qt_metacast(_clname);
}

int LUAuthServerHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RakMessageHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
