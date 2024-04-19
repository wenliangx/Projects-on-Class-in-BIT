/****************************************************************************
** Meta object code from reading C++ file 'gobangwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gobangwindow/gobangwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gobangwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGobangWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGobangWindowENDCLASS = QtMocHelpers::stringData(
    "GobangWindow",
    "GobangBack",
    "",
    "OpenSetting",
    "PickSide",
    "Restart",
    "mouseMoveEvent",
    "QMouseEvent*",
    "event",
    "mousePressEvent"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGobangWindowENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[13];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[8];
    char stringdata6[15];
    char stringdata7[13];
    char stringdata8[6];
    char stringdata9[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGobangWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGobangWindowENDCLASS_t qt_meta_stringdata_CLASSGobangWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "GobangWindow"
        QT_MOC_LITERAL(13, 10),  // "GobangBack"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 11),  // "OpenSetting"
        QT_MOC_LITERAL(37, 8),  // "PickSide"
        QT_MOC_LITERAL(46, 7),  // "Restart"
        QT_MOC_LITERAL(54, 14),  // "mouseMoveEvent"
        QT_MOC_LITERAL(69, 12),  // "QMouseEvent*"
        QT_MOC_LITERAL(82, 5),  // "event"
        QT_MOC_LITERAL(88, 15)   // "mousePressEvent"
    },
    "GobangWindow",
    "GobangBack",
    "",
    "OpenSetting",
    "PickSide",
    "Restart",
    "mouseMoveEvent",
    "QMouseEvent*",
    "event",
    "mousePressEvent"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGobangWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    1,   52,    2, 0x08,    3 /* Private */,
       5,    0,   55,    2, 0x08,    5 /* Private */,
       6,    1,   56,    2, 0x08,    6 /* Private */,
       9,    1,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject GobangWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSGobangWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGobangWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGobangWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GobangWindow, std::true_type>,
        // method 'GobangBack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenSetting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PickSide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Restart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mouseMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mousePressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>
    >,
    nullptr
} };

void GobangWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GobangWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->GobangBack(); break;
        case 1: _t->OpenSetting(); break;
        case 2: _t->PickSide((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->Restart(); break;
        case 4: _t->mouseMoveEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *GobangWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GobangWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGobangWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GobangWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
