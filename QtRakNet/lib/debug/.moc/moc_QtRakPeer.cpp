/****************************************************************************
** Meta object code from reading C++ file 'QtRakPeer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../QtRakPeer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtRakPeer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtRakPeer_t {
    QByteArrayData data[5];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtRakPeer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtRakPeer_t qt_meta_stringdata_QtRakPeer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QtRakPeer"
QT_MOC_LITERAL(1, 10, 7), // "Recieve"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "SystemIndex"
QT_MOC_LITERAL(4, 31, 13) // "SystemAddress"

    },
    "QtRakPeer\0Recieve\0\0SystemIndex\0"
    "SystemAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtRakPeer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 3, 0x80000000 | 4, QMetaType::QByteArray,    2,    2,    2,    2,

       0        // eod
};

void QtRakPeer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtRakPeer *_t = static_cast<QtRakPeer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Recieve((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< SystemIndex(*)>(_a[2])),(*reinterpret_cast< SystemAddress(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QtRakPeer::*_t)(unsigned int , SystemIndex , SystemAddress , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QtRakPeer::Recieve)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QtRakPeer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtRakPeer.data,
      qt_meta_data_QtRakPeer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtRakPeer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtRakPeer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtRakPeer.stringdata0))
        return static_cast<void*>(const_cast< QtRakPeer*>(this));
    return QObject::qt_metacast(_clname);
}

int QtRakPeer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QtRakPeer::Recieve(unsigned int _t1, SystemIndex _t2, SystemAddress _t3, QByteArray _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
