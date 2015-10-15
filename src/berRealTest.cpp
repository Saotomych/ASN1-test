/*
 * berRealTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berRealTest.h"

TestBerReal::TestBerReal()
{

}

TestBerReal::TestBerReal(double real): CBerReal(real)
{

}

TestBerReal::TestBerReal(QByteArray& code): CBerReal(code)
{

}

void TestBerReal::testEncodeDecodeOK(double expecteddata, bool expl)
{
	CBerByteArrayOutputStream berOStream(50);
	encode(berOStream, expl);

	QByteArray encodeResult(berOStream.getByteArray());
	CBerByteArrayInputStream berIStream(encodeResult);
	decode(berIStream, expl);

	QString str(QString("TestBerReal: encode/decode wrong. Expected value = %1").arg(expecteddata));
	CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(str.toStdString(), expecteddata, m_Real, 0.001);
}

void ASN1berRealTest::runTest()
{
	{
		TestBerReal berReal(0);
		berReal.testEncodeDecodeOK(0, true);
	}

	{
		TestBerReal berReal(1.5);
		berReal.testEncodeDecodeOK(1.5, true);
	}

	{
		TestBerReal berReal(std::numeric_limits<double>::infinity());
		berReal.testEncodeDecodeOK(std::numeric_limits<double>::infinity(), true);
	}
}


