#include <QCoreApplication>

#ifndef ASN1TEST_H
#define ASN1TEST_H

#define UNITTEST

#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/XmlOutputterHook.h>
#include <cppunit/XmlOutputter.h>

#include "berByteArrayOutputStream.h"
#include "berIdentifier.h"
#include "berLength.h"
#include "berOctetString.h"
#include "berGeneralizedTime.h"
#include "berInteger.h"
#include "berObjectIdentifier.h"
#include "berReal.h"

class ASN1berGeneralizedTimeTest: public CppUnit::TestCase
{
public:
	ASN1berGeneralizedTimeTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berIntegerTest: public CppUnit::TestCase
{
public:
	ASN1berIntegerTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berObjectIdentifierTest: public CppUnit::TestCase
{
public:
	ASN1berObjectIdentifierTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berOctetStringTest: public CppUnit::TestCase
{
public:
	ASN1berOctetStringTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berRealTest: public CppUnit::TestCase
{
public:
	ASN1berRealTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berIdentifierTest: public CppUnit::TestCase
{
public:
	ASN1berIdentifierTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

class ASN1berLengthTest: public CppUnit::TestCase
{
public:
	ASN1berLengthTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif
