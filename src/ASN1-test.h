#include <QCoreApplication>

#ifndef ASN1TEST_H
#define ASN1TEST_H

#define UNITTEST

#include <string>

#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/XmlOutputterHook.h>
#include <cppunit/XmlOutputter.h>

#include "berByteArrayOutputStream.h"
#include "berByteArrayInputStream.h"
#include "berIdentifier.h"
#include "berLength.h"
#include "berOctetString.h"
#include "berGeneralizedTime.h"
#include "berInteger.h"
#include "berObjectIdentifier.h"
#include "berReal.h"

void checkTestOK(std::string message, QByteArray& expected, QByteArray& result);

#endif
