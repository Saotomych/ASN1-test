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

INCLUDEPATH += ../ASN1/include
INCLUDEPATH += $(JENKINS_HOME)/jobs/ASN1/workspace/include

SOURCES += src/berGeneralizedTimeTest.cpp \
	src/berIdentifierTest.cpp \
	src/berIntegerTest.cpp \
	src/berLengthTest.cpp \
	src/berObjectIdentifierTest.cpp \
	src/berOctetStringTest.cpp \
	src/berOutputStreamAutoResizeTest.cpp \
	src/berRealTest.cpp \
	src/ASN1-test.cpp

HEADERS += src/berGeneralizedTimeTest.h \
	src/berIdentifierTest.h \
	src/berIntegerTest.h \
	src/berLengthTest.h \
	src/berObjectIdentifierTest.h \
	src/berOctetStringTest.h \
	src/berOutputStreamAutoResizeTest.h \
	src/berRealTest.h \
	src/ASN1-test.h

CONFIG (debug, debug|release){
    OBJECTS_DIR = build/debug
	LIBS += -L/home/alexey/workprjs/ASN1/bin -lasn1d -lcppunit -lgcov
	DEFINES += DEBUG
	TARGET = asn1-testd	
} else {
    OBJECTS_DIR = build/release
	LIBS += -L/home/alexey/workprjs/ASN1/bin -lasn1 -lcppunit -lgcov
	TARGET = asn1-test
}

CONFIG += debug_and_release build_all
