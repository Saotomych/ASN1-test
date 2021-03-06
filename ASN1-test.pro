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

unix {
	CONFIG (debug, debug|release){
	    OBJECTS_DIR = build/debug
		LIBS += -L../ASN1/bin -L$(JENKINS_HOME)/jobs/ASN1/workspace/bin -lasn1d -lcppunit -lgcov
		DEFINES += DEBUG
		TARGET = asn1-testd	
		
		QMAKE_CXXFLAGS_RELEASE -= -O
		QMAKE_CXXFLAGS_RELEASE -= -O1
		QMAKE_CXXFLAGS_RELEASE -= -O2
		QMAKE_CXXFLAGS += -O0 -fprofile-arcs -ftest-coverage -fPIC
		
	} else {
	    OBJECTS_DIR = build/release
		LIBS += -L../ASN1/bin -L$(JENKINS_HOME)/jobs/ASN1/workspace/bin -lasn1 -lcppunit
		TARGET = asn1-test
		
		QMAKE_CXXFLAGS_RELEASE += -fPIC
	}
	
	QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
	
}else{
    TARGET = asn1-test-notunix
}

CONFIG += debug_and_release build_all
