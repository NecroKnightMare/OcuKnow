/****************************************************************************
** Meta object code from reading C++ file 'introwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UI/introwidget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'introwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_IntroWidget_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[15];
    char stringdata5[22];
    char stringdata6[15];
    char stringdata7[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_IntroWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_IntroWidget_t qt_meta_stringdata_IntroWidget = {
    {
        QT_MOC_LITERAL(0, 11),  // "IntroWidget"
        QT_MOC_LITERAL(12, 22),  // "enterStudyGuideClicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 15),  // "takeQuizClicked"
        QT_MOC_LITERAL(52, 14),  // "creditsClicked"
        QT_MOC_LITERAL(67, 21),  // "handleEnterStudyGuide"
        QT_MOC_LITERAL(89, 14),  // "handleTakeQuiz"
        QT_MOC_LITERAL(104, 13)   // "handleCredits"
    },
    "IntroWidget",
    "enterStudyGuideClicked",
    "",
    "takeQuizClicked",
    "creditsClicked",
    "handleEnterStudyGuide",
    "handleTakeQuiz",
    "handleCredits"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_IntroWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject IntroWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_IntroWidget.offsetsAndSizes,
    qt_meta_data_IntroWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_IntroWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<IntroWidget, std::true_type>,
        // method 'enterStudyGuideClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'takeQuizClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'creditsClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleEnterStudyGuide'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTakeQuiz'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCredits'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void IntroWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IntroWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->enterStudyGuideClicked(); break;
        case 1: _t->takeQuizClicked(); break;
        case 2: _t->creditsClicked(); break;
        case 3: _t->handleEnterStudyGuide(); break;
        case 4: _t->handleTakeQuiz(); break;
        case 5: _t->handleCredits(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IntroWidget::*)();
            if (_t _q_method = &IntroWidget::enterStudyGuideClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IntroWidget::*)();
            if (_t _q_method = &IntroWidget::takeQuizClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IntroWidget::*)();
            if (_t _q_method = &IntroWidget::creditsClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *IntroWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntroWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IntroWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int IntroWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void IntroWidget::enterStudyGuideClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IntroWidget::takeQuizClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IntroWidget::creditsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
