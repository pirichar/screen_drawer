/****************************************************************************
** Meta object code from reading C++ file 'Toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Toolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Toolbar_t {
    const uint offsetsAndSize[38];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Toolbar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Toolbar_t qt_meta_stringdata_Toolbar = {
    {
QT_MOC_LITERAL(0, 7), // "Toolbar"
QT_MOC_LITERAL(8, 11), // "toolChanged"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 4), // "Tool"
QT_MOC_LITERAL(26, 4), // "tool"
QT_MOC_LITERAL(31, 12), // "colorChanged"
QT_MOC_LITERAL(44, 5), // "color"
QT_MOC_LITERAL(50, 16), // "thicknessChanged"
QT_MOC_LITERAL(67, 9), // "thickness"
QT_MOC_LITERAL(77, 14), // "opacityChanged"
QT_MOC_LITERAL(92, 7), // "opacity"
QT_MOC_LITERAL(100, 15), // "fontSizeChanged"
QT_MOC_LITERAL(116, 4), // "size"
QT_MOC_LITERAL(121, 13), // "undoTriggered"
QT_MOC_LITERAL(135, 14), // "clearTriggered"
QT_MOC_LITERAL(150, 9), // "selectPen"
QT_MOC_LITERAL(160, 10), // "selectText"
QT_MOC_LITERAL(171, 12), // "selectEraser"
QT_MOC_LITERAL(184, 15) // "openColorDialog"

    },
    "Toolbar\0toolChanged\0\0Tool\0tool\0"
    "colorChanged\0color\0thicknessChanged\0"
    "thickness\0opacityChanged\0opacity\0"
    "fontSizeChanged\0size\0undoTriggered\0"
    "clearTriggered\0selectPen\0selectText\0"
    "selectEraser\0openColorDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Toolbar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       5,    1,   83,    2, 0x06,    3 /* Public */,
       7,    1,   86,    2, 0x06,    5 /* Public */,
       9,    1,   89,    2, 0x06,    7 /* Public */,
      11,    1,   92,    2, 0x06,    9 /* Public */,
      13,    0,   95,    2, 0x06,   11 /* Public */,
      14,    0,   96,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,   97,    2, 0x08,   13 /* Private */,
      16,    0,   98,    2, 0x08,   14 /* Private */,
      17,    0,   99,    2, 0x08,   15 /* Private */,
      18,    0,  100,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Toolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Toolbar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->toolChanged((*reinterpret_cast< std::add_pointer_t<Tool>>(_a[1]))); break;
        case 1: _t->colorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 2: _t->thicknessChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->opacityChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->fontSizeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->undoTriggered(); break;
        case 6: _t->clearTriggered(); break;
        case 7: _t->selectPen(); break;
        case 8: _t->selectText(); break;
        case 9: _t->selectEraser(); break;
        case 10: _t->openColorDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Toolbar::*)(Tool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::toolChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::colorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::thicknessChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::opacityChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::fontSizeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::undoTriggered)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Toolbar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Toolbar::clearTriggered)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject Toolbar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Toolbar.offsetsAndSize,
    qt_meta_data_Toolbar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Toolbar_t
, QtPrivate::TypeAndForceComplete<Toolbar, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Tool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Toolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Toolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Toolbar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Toolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Toolbar::toolChanged(Tool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Toolbar::colorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Toolbar::thicknessChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Toolbar::opacityChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Toolbar::fontSizeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Toolbar::undoTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Toolbar::clearTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
