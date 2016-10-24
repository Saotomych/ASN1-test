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

TestBerReal::TestBerReal(double real): m_Value(real)
{

}

TestBerReal::TestBerReal(QByteArray& code): m_Value(code)
{

}

void TestBerReal::testEncodeDecodeOK(double expecteddata, bool expl)
{
	CBerByteArrayOutputStream berOStream(50);
	if (expl)
		m_Value.startEncode(berOStream);
	else
		m_Value.nextEncode(berOStream);

	QByteArray encodeResult(berOStream.getByteArray());
	CBerByteArrayInputStream berIStream(encodeResult);
	if (expl)
		m_Value.startDecode(berIStream);
	else
		m_Value.nextDecode(berIStream);

	double Real = *m_Value.getValue();

	QString str(QString("TestBerReal: encode/decode wrong. Expected value = %1").arg(expecteddata));
	CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE(str.toStdString(), expecteddata, Real, 0.001);
}

void ASN1berRealTest::runTest()
{
	{
		TestBerReal berReal(0);
		berReal.testEncodeDecodeOK(0, true);
	}

	{
		TestBerReal berReal(0.15625);
		berReal.testEncodeDecodeOK(0.15625, true);
	}

	{
		TestBerReal berReal(8.726);
		berReal.testEncodeDecodeOK(8.726, true);
	}

	{
		TestBerReal berReal(-2350.14);
		berReal.testEncodeDecodeOK(-2350.14, true);
	}

	{
		TestBerReal berReal(std::numeric_limits<double>::infinity());
		berReal.testEncodeDecodeOK(std::numeric_limits<double>::infinity(), true);
	}
}


