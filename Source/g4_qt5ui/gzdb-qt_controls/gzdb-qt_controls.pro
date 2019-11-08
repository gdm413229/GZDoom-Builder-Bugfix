CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(gzdb-qt_controlsplugin)
TEMPLATE    = lib

HEADERS     = g4_qtjackedupspinboxplugin.h g4_qtangleselectorplugin.h g4_qtimageviewplugin.h g4_qtimagebrowserviewplugin.h g4_qtretractablepanelplugin.h g4_qtspriteviewplugin.h gzdb-qt_controls.h
SOURCES     = g4_qtjackedupspinboxplugin.cpp g4_qtangleselectorplugin.cpp g4_qtimageviewplugin.cpp g4_qtimagebrowserviewplugin.cpp g4_qtretractablepanelplugin.cpp g4_qtspriteviewplugin.cpp gzdb-qt_controls.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(g4_qtangleselector.pri)
include(g4_qtimagebrowserview.pri)
include(g4_qtimageview.pri)
include(g4_qtspriteview.pri)
include(g4_qtretractablepanel.pri)
include(g4_qtjackedupspinbox.pri)
