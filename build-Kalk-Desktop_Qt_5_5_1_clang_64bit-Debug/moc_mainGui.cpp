/****************************************************************************
** Meta object code from reading C++ file 'mainGui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../c++/view/mainGui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainGui_t {
    QByteArrayData data[15];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainGui_t qt_meta_stringdata_mainGui = {
    {
QT_MOC_LITERAL(0, 0, 7), // "mainGui"
QT_MOC_LITERAL(1, 8, 8), // "push_qle"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "remove_qle"
QT_MOC_LITERAL(4, 29, 13), // "drawAndReturn"
QT_MOC_LITERAL(5, 43, 10), // "clearEntry"
QT_MOC_LITERAL(6, 54, 12), // "intersezione"
QT_MOC_LITERAL(7, 67, 10), // "saveResult"
QT_MOC_LITERAL(8, 78, 10), // "showResult"
QT_MOC_LITERAL(9, 89, 11), // "rect2Points"
QT_MOC_LITERAL(10, 101, 9), // "dist2item"
QT_MOC_LITERAL(11, 111, 4), // "area"
QT_MOC_LITERAL(12, 116, 9), // "perimetro"
QT_MOC_LITERAL(13, 126, 15), // "paralsrettapunt"
QT_MOC_LITERAL(14, 142, 14) // "perppuntoretta"

    },
    "mainGui\0push_qle\0\0remove_qle\0drawAndReturn\0"
    "clearEntry\0intersezione\0saveResult\0"
    "showResult\0rect2Points\0dist2item\0area\0"
    "perimetro\0paralsrettapunt\0perppuntoretta"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainGui *_t = static_cast<mainGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->push_qle(); break;
        case 1: _t->remove_qle(); break;
        case 2: _t->drawAndReturn(); break;
        case 3: _t->clearEntry(); break;
        case 4: _t->intersezione(); break;
        case 5: _t->saveResult(); break;
        case 6: _t->showResult(); break;
        case 7: _t->rect2Points(); break;
        case 8: _t->dist2item(); break;
        case 9: _t->area(); break;
        case 10: _t->perimetro(); break;
        case 11: _t->paralsrettapunt(); break;
        case 12: _t->perppuntoretta(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject mainGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainGui.data,
      qt_meta_data_mainGui,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainGui::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainGui.stringdata0))
        return static_cast<void*>(const_cast< mainGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
