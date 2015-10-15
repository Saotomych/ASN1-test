/*
 * berLengthTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berLengthTest.h"

using namespace std;

void ASN1berLengthTest::runTest()
{

	CBerByteArrayOutputStream berOStream(50);

	// Test 1
	{
		CBerLength::encodeLength(berOStream, 128);
		quint8 expecteddata[] = { 0x81, 0x80 };
		quint32 expectedsize = sizeof(expecteddata) / sizeof(expecteddata[0]);

		QByteArray resByteArray = berOStream.getByteArray();

		for (quint32 i = 0; i < expectedsize; ++i)
			CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berLength Test 1: ", expecteddata[i], (quint8) resByteArray[i]);
	}

	// Test 2
	{
		CBerLength::encodeLength(berOStream, 8);
		quint8 expecteddata[] = { 0x08 };
		quint32 expectedsize = sizeof(expecteddata) / sizeof(expecteddata[0]);

		QByteArray resByteArray = berOStream.getByteArray();

		for (quint32 i = 0; i < expectedsize; ++i)
			CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berLength Test 2: ", expecteddata[i], (quint8) resByteArray[i]);
	}

	// Test 3
	{
		quint8 expecteddata[] = { 0x81, 0x80 };

		QByteArray byteArray;
		for (quint8 v: expecteddata) byteArray.push_back(v);

		CBerByteArrayInputStream berIStream(byteArray);

		CBerLength berLength;

		berLength.decode(berIStream);

		CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berLength Test 3: ", (quint32) 128, berLength.getVal());
	}
}


