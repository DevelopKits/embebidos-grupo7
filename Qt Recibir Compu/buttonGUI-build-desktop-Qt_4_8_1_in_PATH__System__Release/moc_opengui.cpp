/****************************************************************************
** Meta object code from reading C++ file 'opengui.h'
**
** Created: Tue Oct 8 21:26:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../buttonGUI/opengui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'opengui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenGUI[] = {

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
       9,    8,    8,    8, 0x08,
      24,    8,    8,    8, 0x08,
      44,    8,    8,    8, 0x08,
      61,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenGUI[] = {
    "OpenGUI\0\0handleButton()\0handleButtonPause()\0"
    "handleButtonUp()\0handleButtonDown()\0"
};

void OpenGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenGUI *_t = static_cast<OpenGUI *>(_o);
        switch (_id) {
        case 0: _t->handleButton(); break;
        case 1: _t->handleButtonPause(); break;
        case 2: _t->handleButtonUp(); break;
        case 3: _t->handleButtonDown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OpenGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenGUI::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OpenGUI,
      qt_meta_data_OpenGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenGUI))
        return static_cast<void*>(const_cast< OpenGUI*>(this));
    return QWidget::qt_metacast(_clname);
}

int OpenGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
