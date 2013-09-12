# -------------------------------------------------
# Project created by QtCreator 2013-09-03T14:51:47
# -------------------------------------------------
QT += testlib
QT -= gui
TARGET = assign3
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    gate.cpp \
    andgate.cpp \
    orgate.cpp
HEADERS += gate.h \
    andgate.h \ orgate.h
OTHER_FILES += circuit.txt \
    ExpectedOutput.txt
