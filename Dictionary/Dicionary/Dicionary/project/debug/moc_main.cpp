/****************************************************************************
** Meta object code from reading C++ file 'main.h'
**
** Created: Wed Oct 31 11:44:33 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      17,    6,    6,    6, 0x08,
      27,    6,    6,    6, 0x08,
      37,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyWin[] = {
    "MyWin\0\0myslot1()\0myslot2()\0myslot3()\0"
    "myslot4()\0"
};

void MyWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyWin *_t = static_cast<MyWin *>(_o);
        switch (_id) {
        case 0: _t->myslot1(); break;
        case 1: _t->myslot2(); break;
        case 2: _t->myslot3(); break;
        case 3: _t->myslot4(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyWin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyWin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWin,
      qt_meta_data_MyWin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWin))
        return static_cast<void*>(const_cast< MyWin*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
