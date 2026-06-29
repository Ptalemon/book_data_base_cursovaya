TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Student.cpp \
        book.cpp \
        librarydb.cpp \
        main.cpp \
        menu.cpp \
        transaction.cpp

HEADERS += \
    Student.h \
    book.h \
    librarydb.h \
    menu.h \
    transaction.h
