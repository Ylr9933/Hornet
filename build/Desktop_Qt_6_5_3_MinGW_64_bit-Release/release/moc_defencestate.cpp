/****************************************************************************
** Meta object code from reading C++ file 'defencestate.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../defencestate.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'defencestate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSDefenceStateENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDefenceStateENDCLASS = QtMocHelpers::stringData(
    "DefenceState",
    "onMouseEvent",
    "",
    "QMouseEvent*",
    "event",
    "mousePoint",
    "eventType"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDefenceStateENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[6];
    char stringdata5[11];
    char stringdata6[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDefenceStateENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDefenceStateENDCLASS_t qt_meta_stringdata_CLASSDefenceStateENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "DefenceState"
        QT_MOC_LITERAL(13, 12),  // "onMouseEvent"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 12),  // "QMouseEvent*"
        QT_MOC_LITERAL(40, 5),  // "event"
        QT_MOC_LITERAL(46, 10),  // "mousePoint"
        QT_MOC_LITERAL(57, 9)   // "eventType"
    },
    "DefenceState",
    "onMouseEvent",
    "",
    "QMouseEvent*",
    "event",
    "mousePoint",
    "eventType"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDefenceStateENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   20,    2, 0x09,    1 /* Protected */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint, QMetaType::Int,    4,    5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject DefenceState::staticMetaObject = { {
    QMetaObject::SuperData::link<State::staticMetaObject>(),
    qt_meta_stringdata_CLASSDefenceStateENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDefenceStateENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDefenceStateENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DefenceState, std::true_type>,
        // method 'onMouseEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void DefenceState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DefenceState *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onMouseEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *DefenceState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefenceState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDefenceStateENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return State::qt_metacast(_clname);
}

int DefenceState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
