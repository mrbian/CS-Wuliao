#-------------------------------------------------
#
# Project created by QtCreator 2015-07-21T14:16:11
#
#-------------------------------------------------

QT       += core gui

TARGET = wuliao
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    mainview.cpp \
    dialog_addfriend.cpp \
    dialog_addfriend_check.cpp \
    dialog_addgroup.cpp \
    dialog_addgroup_check.cpp \
    dialog_creategroup.cpp \
    dialog_settings.cpp \
    single_chat_window.cpp \
    group_chat_window.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    mainview.h \
    dialog_addfriend.h \
    dialog_addfriend_check.h \
    dialog_addgroup.h \
    dialog_addgroup_check.h \
    dialog_creategroup.h \
    dialog_settings.h \
    single_chat_window.h \
    group_chat_window.h

FORMS    += mainwindow.ui \
    dialog.ui \
    mainview.ui \
    dialog_addfriend.ui \
    dialog_addfriend_check.ui \
    dialog_addgroup.ui \
    dialog_addgroup_check.ui \
    dialog_creategroup.ui \
    dialog_settings.ui \
    single_chat_window.ui \
    group_chat_window.ui

OTHER_FILES +=

RESOURCES += \
    resource.qrc
