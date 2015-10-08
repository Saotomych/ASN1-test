#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T14:05:00
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

CONFIG   += console
CONFIG 	 += c++11
CONFIG   -= app_bundle
CONFIG   += static

TEMPLATE = app

DESTDIR = bin
VERSION = 0.0.0.0

INCLUDEPATH += /home/alexey/workprjs/ASN1-test/src

SOURCES += src/ASN1-test.cpp

HEADERS += src/ASN1-test.h

CONFIG (debug, debug|release){
    OBJECTS_DIR = build/debug
	LIBS += -L/home/alexey/workprjs/ASN1/bin -lasn1 -lcppunit -lgcov
	DEFINES += DEBUG
	TARGET = asn1-testd	
} else {
    OBJECTS_DIR = build/release
	LIBS += -L/home/alexey/workprjs/ASN1/bin -lasn1 -lcppunit -lgcov
	TARGET = asn1-test
}

CONFIG += debug_and_release build_all
