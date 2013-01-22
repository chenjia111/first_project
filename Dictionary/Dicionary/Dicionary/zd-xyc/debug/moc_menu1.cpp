/****************************************************************************
** Meta object code from reading C++ file 'menu1.h'
**
** Created: Wed Oct 31 18:49:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../menu1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyMain[] = {

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

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      22,   17,    7,    7, 0x08,
      43,    7,    7,    7, 0x08,
      58,    7,    7,    7, 0x08,
      72,    7,    7,    7, 0x08,
      81,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyMain[] = {
    "MyMain\0\0myslot()\0text\0editwordfun(QString)\0"
    "btnsearchfun()\0edittextfun()\0insert()\0"
    "myku()\0"
};

void MyMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyMain *_t = static_cast<MyMain *>(_o);
        switch (_id) {
        case 0: _t->myslot(); break;
        case 1: _t->editwordfun((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->btnsearchfun(); break;
        case 3: _t->edittextfun(); break;
        case 4: _t->insert(); break;
        case 5: _t->myku(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyMain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyMain,
      qt_meta_data_MyMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyMain))
        return static_cast<void*>(const_cast< MyMain*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
