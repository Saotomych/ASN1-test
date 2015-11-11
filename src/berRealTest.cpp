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
	m_Value.encode(berOStream, expl);

	QByteArray encodeResult(berOStream.getByteArray());
	CBerByteArrayInputStream berIStream(encodeResult);
	m_Value.decode(berIStream, expl);

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
		TestBerReal berReal(1.5);
		berReal.testEncodeDecodeOK(1.5, true);
	}

	{
		TestBerReal berReal(std::numeric_limits<double>::infinity());
		berReal.testEncodeDecodeOK(std::numeric_limits<double>::infinity(), true);
	}
}


