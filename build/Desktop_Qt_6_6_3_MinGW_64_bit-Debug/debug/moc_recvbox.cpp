/****************************************************************************
** Meta object code from reading C++ file 'recvbox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../recvbox.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recvbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSRecvBoxENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSRecvBoxENDCLASS = QtMocHelpers::stringData(
    "RecvBox",
    "setAvatar",
    "",
    "avtar",
    "setText",
    "text",
    "setName",
    "name",
    "setTitle",
    "title"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRecvBoxENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[8];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[8];
    char stringdata5[5];
    char stringdata6[8];
    char stringdata7[5];
    char stringdata8[9];
    char stringdata9[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRecvBoxENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRecvBoxENDCLASS_t qt_meta_stringdata_CLASSRecvBoxENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "RecvBox"
        QT_MOC_LITERAL(8, 9),  // "setAvatar"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 5),  // "avtar"
        QT_MOC_LITERAL(25, 7),  // "setText"
        QT_MOC_LITERAL(33, 4),  // "text"
        QT_MOC_LITERAL(38, 7),  // "setName"
        QT_MOC_LITERAL(46, 4),  // "name"
        QT_MOC_LITERAL(51, 8),  // "setTitle"
        QT_MOC_LITERAL(60, 5)   // "title"
    },
    "RecvBox",
    "setAvatar",
    "",
    "avtar",
    "setText",
    "text",
    "setName",
    "name",
    "setTitle",
    "title"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRecvBoxENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       4,    1,   41,    2, 0x0a,    3 /* Public */,
       6,    1,   44,    2, 0x0a,    5 /* Public */,
       8,    1,   47,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPixmap,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject RecvBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSRecvBoxENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRecvBoxENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRecvBoxENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RecvBox, std::true_type>,
        // method 'setAvatar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        // method 'setText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setTitle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void RecvBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RecvBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setAvatar((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1]))); break;
        case 1: _t->setText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->setTitle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *RecvBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRecvBoxENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RecvBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
