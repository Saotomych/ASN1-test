/*
 * berOctetStringTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berOctetStringTest.h"

using namespace std;


TestBerOctetString::TestBerOctetString()
{

}

TestBerOctetString::TestBerOctetString(QByteArray& octetString)
{
	CBerOctetString obj(octetString);
	m_Value = obj;
}

void TestBerOctetString::encodeTest(char* expectedData, quint32 expectedLen)
{
	CBerByteArrayOutputStream berStream(50);

	quint32 length = m_Value.encode(berStream, true);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("berOctetStringTest Test: encode length error", expectedLen, length);

	QByteArray expectedByteArray(expectedData, expectedLen);

	QByteArray resByteArray = berStream.getByteArray();

	checkTestOK("berOctetStringTest Test: encode data error", expectedByteArray, resByteArray);
}

void TestBerOctetString::decodeTest(char* data, quint32 len, quint32 expectedLen)
{
	QByteArray byteArray(data, len);
	CBerByteArrayInputStream berStream( byteArray );

	m_Value.decode(berStream, true);

	QByteArray OctetString = *(m_Value.getValue());

	CPPUNIT_ASSERT_EQUAL_MESSAGE("berOctetStringTest Test: decode length error", (int) expectedLen, OctetString.size());
}

void ASN1berOctetStringTest::runTest()
{

	// Test 1 - encode
	{
		char data[] = { 0x01, 0x02, 0x03 };
		QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
		TestBerOctetString berOctetString(byteArray);

		char expecteddata[] = { 0x04, 0x03, 0x01, 0x02, 0x03 };
		berOctetString.encodeTest(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));
	}

	// Test 2 - decode
	{
		char data[] = { 0x04, 0x00 };
		TestBerOctetString berOctetString;

		berOctetString.decodeTest(data, sizeof(data)/sizeof(data[0]), 0);
	}
}




