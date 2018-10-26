TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += debug_and_release

QMAKE_CXXFLAGS += -Wall -Werror

SOURCES += main.cpp \
    token.cpp \
    condition_parser.cpp \
    condition_parser_test.cpp \
    database.cpp \
    date.cpp \
    data_test.cpp \
    node.cpp

HEADERS += \
    token.h \
    condition_parser.h \
    test_runner.h \
    database.h \
    date.h \
    node.h
