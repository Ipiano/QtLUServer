/****************************************************************************
** Meta object code from reading C++ file 'rakmessagehandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MessageHandlers/rakmessagehandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rakmessagehandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RakMessageHandler_t {
    QByteArrayData data[14];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RakMessageHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RakMessageHandler_t qt_meta_stringdata_RakMessageHandler = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RakMessageHandler"
QT_MOC_LITERAL(1, 18, 11), // "sendMessage"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "SystemAddress"
QT_MOC_LITERAL(4, 45, 15), // "VERSION_CONFIRM"
QT_MOC_LITERAL(5, 61, 12), // "SystemIndex&"
QT_MOC_LITERAL(6, 74, 6), // "sysInd"
QT_MOC_LITERAL(7, 81, 14), // "SystemAddress&"
QT_MOC_LITERAL(8, 96, 7), // "sysAddr"
QT_MOC_LITERAL(9, 104, 11), // "QByteArray&"
QT_MOC_LITERAL(10, 116, 4), // "data"
QT_MOC_LITERAL(11, 121, 13), // "handleMessage"
QT_MOC_LITERAL(12, 135, 6), // "header"
QT_MOC_LITERAL(13, 142, 11) // "SystemIndex"

    },
    "RakMessageHandler\0sendMessage\0\0"
    "SystemAddress\0VERSION_CONFIRM\0"
    "SystemIndex&\0sysInd\0SystemAddress&\0"
    "sysAddr\0QByteArray&\0data\0handleMessage\0"
    "header\0SystemIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RakMessageHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   34,    2, 0x08 /* Private */,
      11,    4,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 9,    6,    8,   10,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 13, 0x80000000 | 3, QMetaType::QByteArray,   12,    6,    8,   10,

       0        // eod
};

void RakMessageHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RakMessageHandler *_t = static_cast<RakMessageHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SystemAddress(*)>(_a[2]))); break;
        case 1: _t->VERSION_CONFIRM((*reinterpret_cast< SystemIndex(*)>(_a[1])),(*reinterpret_cast< SystemAddress(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 2: _t->handleMessage((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< SystemIndex(*)>(_a[2])),(*reinterpret_cast< SystemAddress(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RakMessageHandler::*_t)(QByteArray , SystemAddress );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RakMessageHandler::sendMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RakMessageHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RakMessageHandler.data,
      qt_meta_data_RakMessageHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RakMessageHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RakMessageHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RakMessageHandler.stringdata0))
        return static_cast<void*>(const_cast< RakMessageHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int RakMessageHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void RakMessageHandler::sendMessage(QByteArray _t1, SystemAddress _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
