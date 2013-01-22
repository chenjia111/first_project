/****************************************************************************
** Meta object code from reading C++ file 'menu2.h'
**
** Created: Wed Oct 31 18:49:17 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyKu[] = {

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
       6,    5,    5,    5, 0x08,
      18,    5,    5,    5, 0x08,
      30,    5,    5,    5, 0x08,
      39,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyKu[] = {
    "MyKu\0\0appendfun()\0reloadfun()\0delfun()\0"
    "savefun()\0"
};

void MyKu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyKu *_t = static_cast<MyKu *>(_o);
        switch (_id) {
        case 0: _t->appendfun(); break;
        case 1: _t->reloadfun(); break;
        case 2: _t->delfun(); break;
        case 3: _t->savefun(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyKu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyKu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyKu,
      qt_meta_data_MyKu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyKu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyKu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyKu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyKu))
        return static_cast<void*>(const_cast< MyKu*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyKu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
