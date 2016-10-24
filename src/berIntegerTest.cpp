/*
 * berIntegerTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berIntegerTest.h"

CIntegerUnivPrim::CIntegerUnivPrim()
{
	m_Value = 0;
	CBerIdentifier berID(CBerIdentifier::APPLICATION_CLASS, CBerIdentifier::PRIMITIVE, CBerIdentifier::INTEGER_TAG);
	m_berID = berID;
}

CIntegerUnivPrim::CIntegerUnivPrim(qint64 val)
{
	m_Value = val;
	CBerIdentifier berID(CBerIdentifier::APPLICATION_CLASS, CBerIdentifier::PRIMITIVE, CBerIdentifier::INTEGER_TAG);
	m_berID = berID;
}

quint32 CIntegerUnivPrim::encode(CBerByteArrayOutputStream& berBAOStream, bool expl)
{
	quint32 codeLength = 0;
	if (expl)
		codeLength = m_Value.startEncode(berBAOStream);
	else
		codeLength = m_Value.nextEncode(berBAOStream);

	return codeLength;
}

void CIntegerUnivPrim::testEncodeOK(char* expecteddata, int expectedlen, bool expl)
{
	CBerByteArrayOutputStream berStream(50);

	int length = 0;
	quint32 codeLength = 0;
	if (expl)
		length = m_Value.startEncode(berStream);
	else
		length = m_Value.nextEncode(berStream);

	QString testStr1( QString("berInteger Test encode: length error (val = %1)").arg(length) );

	CPPUNIT_ASSERT_EQUAL_MESSAGE(testStr1.toStdString(), expectedlen, length);

	QByteArray resByteArray = berStream.getByteArray();
	QByteArray expectedByteArray( expecteddata, expectedlen );

	qint64 val = 0;
	qint64 mux = 1;
	for (int i = 1; i < resByteArray.size(); i++ )
	{
		qint64 v = resByteArray[i];
		val += (mux * v);
		mux *= 256;
	}

	QString testStr2( QString("berInteger Test encode: data error (val = %1)").arg(val) );
	checkTestOK(testStr2.toStdString(), expectedByteArray, resByteArray);
}

void CIntegerUnivPrim::testDecode(char* setData, int setLen, qint64 expectedVal, bool expl)
{
	QByteArray setByteArray( setData, setLen );
	CBerByteArrayInputStream berInputStream(setByteArray);

	if (expl)
		m_Value.startDecode(berInputStream);
	else
		m_Value.nextDecode(berInputStream);

	qint64 resVal = *(m_Value.getValue());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("berInteger Test decode: data error", expectedVal, resVal);
}

void ASN1berIntegerTest::runTest()
{
	// Test 51
	{
		CIntegerUnivPrim berInt(51);
		char expecteddata[] = { 0x01, 0x33 };
		berInt.testEncodeOK(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 256
	{
		CIntegerUnivPrim berInt(256);
		char expecteddata[] = { 0x02, 0x01, 0x00 };
		berInt.testEncodeOK(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 0
	{
		CIntegerUnivPrim berInt(0);
		char expecteddata[] = { 0x01, 0x00 };
		berInt.testEncodeOK(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 127
	{
		CIntegerUnivPrim berInt(127);
		char expecteddata[] = { 0x01, 0x7F };
		berInt.testEncodeOK(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 128
	{
		CIntegerUnivPrim berInt(128);
		quint8 expecteddata[] = { 0x02, 0x00, 0x80 };
		berInt.testEncodeOK((char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test -128
	{
		CIntegerUnivPrim berInt(-128);
		quint8 expecteddata[] = { 0x01, 0x80 };
		berInt.testEncodeOK((char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test -129
	{
		CIntegerUnivPrim berInt(-129);
		quint8 expecteddata[] = { 0x02, 0xFF, 0x7F };
		berInt.testEncodeOK((char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 51 true
	{
		CIntegerUnivPrim berInt(51);
		char expecteddata[] = { 0x02, 0x01, 0x33 };
		berInt.testEncodeOK(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), true);
	}

	// Test 5555 true
	{
		CIntegerUnivPrim berInt(5555);
		quint8 expecteddata[] = { 0x02, 0x02, 0x15, 0xB3 };
		berInt.testEncodeOK((char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), true);
	}

	// Test 51 decode
	{
		quint8 data[] = { 0x02, 0x01, 0x33 };
		CIntegerUnivPrim berInt;
		qint64 expectedVal = 51;

		berInt.testDecode( (char*) data, sizeof(data)/sizeof(data[0]), expectedVal, true);
	}

	// Test 5555 decode
	{
		quint8 data[] = { 0x02, 0x02, 0x15, 0xB3 };
		CIntegerUnivPrim berInt;
		qint64 expectedVal = 5555;

		berInt.testDecode( (char*) data, sizeof(data)/sizeof(data[0]), expectedVal, true);
	}

	// Test -64 decode
	{
		quint8 data[] = { 0x02, 0x01, 0xC0 };
		CIntegerUnivPrim berInt;
		qint64 expectedVal = -64;

		berInt.testDecode( (char*) data, sizeof(data)/sizeof(data[0]), expectedVal, true);
	}

	// Test -255 decode
	{
		quint8 data[] = { 0x02, 0x02, 0xFF, 0x01 };
		CIntegerUnivPrim berInt;
		qint64 expectedVal = -255;

		berInt.testDecode( (char*) data, sizeof(data)/sizeof(data[0]), expectedVal, true);
	}

}




