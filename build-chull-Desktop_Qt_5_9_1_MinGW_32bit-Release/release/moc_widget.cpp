/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chull/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[13];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 17), // "on_Random_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "on_Grid_clicked"
QT_MOC_LITERAL(4, 42, 18), // "on_Cluster_clicked"
QT_MOC_LITERAL(5, 61, 17), // "on_Jarvis_clicked"
QT_MOC_LITERAL(6, 79, 20), // "on_QuickHull_clicked"
QT_MOC_LITERAL(7, 100, 22), // "on_Incremental_clicked"
QT_MOC_LITERAL(8, 123, 16), // "on_clear_clicked"
QT_MOC_LITERAL(9, 140, 17), // "on_Graham_clicked"
QT_MOC_LITERAL(10, 158, 24), // "on_graphCheckBox_clicked"
QT_MOC_LITERAL(11, 183, 6), // "ticked"
QT_MOC_LITERAL(12, 190, 24) // "on_generateGraph_clicked"

    },
    "Widget\0on_Random_clicked\0\0on_Grid_clicked\0"
    "on_Cluster_clicked\0on_Jarvis_clicked\0"
    "on_QuickHull_clicked\0on_Incremental_clicked\0"
    "on_clear_clicked\0on_Graham_clicked\0"
    "on_graphCheckBox_clicked\0ticked\0"
    "on_generateGraph_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Random_clicked(); break;
        case 1: _t->on_Grid_clicked(); break;
        case 2: _t->on_Cluster_clicked(); break;
        case 3: _t->on_Jarvis_clicked(); break;
        case 4: _t->on_QuickHull_clicked(); break;
        case 5: _t->on_Incremental_clicked(); break;
        case 6: _t->on_clear_clicked(); break;
        case 7: _t->on_Graham_clicked(); break;
        case 8: _t->on_graphCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_generateGraph_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
