/*
 * berObjectIdentifierTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berObjectIdentifierTest.h"

using namespace std;

TestBerObjectIdentifier::TestBerObjectIdentifier(QVector<qint32>& testOID):
		m_Value( CBerObjectIdentifier(testOID) )
{
}

void TestBerObjectIdentifier::encodeTest(QByteArray& testData)
{
	CBerByteArrayOutputStream berOStream(50);

	qint32 len = m_Value.startEncode(berOStream);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berObjectIdentifier encodeTest: length wrong", 7, len);

	QByteArray resultData = berOStream.getByteArray();
	for (qint32 i = 0; i < testData.size() && i < resultData.size(); ++i)
		CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berObjectIdentifier encodeTest: data wrong", testData[i], resultData[i]);

}

void TestBerObjectIdentifier::decodeTest(QVector<qint32>& testOID, QByteArray& testData)
{
	CBerByteArrayInputStream berInputStream(testData);

	m_Value.startDecode(berInputStream);

	QVector<qint32> ObjectIdentifierComponents = *(m_Value.getValue());

	for (qint32 i = 0; i < testOID.size() && i < ObjectIdentifierComponents.size(); ++i)
		CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berObjectIdentifier decodeTest: data wrong", testOID[i], ObjectIdentifierComponents[i]);

}


QByteArray ASN1berObjectIdentifierTest::getDataForTest1()
{
	quint8 expectedTest1[] = { 0x06, 0x05, 0x28, 0xCA, 0x22, 0x02, 0x03 };
	QByteArray setByteArrayTest1( (char*) expectedTest1, sizeof(expectedTest1) / sizeof(expectedTest1[0]) );

	return setByteArrayTest1;
}

QByteArray ASN1berObjectIdentifierTest::getDataForTest2()
{
	quint8 expectedTest2[] = { 0x06, 0x07, 0x60, 0x85, 0x74, 0x05, 0x08, 0x01, 0x01 };
	QByteArray setByteArrayTest2( (char*) expectedTest2, sizeof(expectedTest2) / sizeof(expectedTest2[0]) );

	return setByteArrayTest2;
}

QVector<qint32> ASN1berObjectIdentifierTest::getDataForObjIdTest1()
{
	qint32 OIComponents[] = { 1, 0, 9506, 2, 3 };
	QVector<qint32> vecOIComponents;
	for (qint32 value: OIComponents) vecOIComponents.push_back(value);

	return vecOIComponents;
}

QVector<qint32> ASN1berObjectIdentifierTest::getDataForObjIdTest2()
{
	qint32 OIComponents[] = { 2, 16, 756, 5, 8, 1, 1 };
	QVector<qint32> vecOIComponents;
	for (qint32 value: OIComponents) vecOIComponents.push_back(value);

	return vecOIComponents;
}

void ASN1berObjectIdentifierTest::runTest()
{
	// Test 1 - encode
	{
		QVector<qint32> vecOIComponents = getDataForObjIdTest1();
		TestBerObjectIdentifier berOID(vecOIComponents);

		QByteArray expectedData = getDataForTest1();
		berOID.encodeTest(expectedData);
	}

	// Test 2 - decode
	{
		QVector<qint32> vecOIComponents = getDataForObjIdTest1();
		TestBerObjectIdentifier berOID(vecOIComponents);

		QByteArray testData = getDataForTest1();
		berOID.decodeTest(vecOIComponents, testData);
	}

	// Test 3 - decode
	{
		QVector<qint32> vecOIComponents = getDataForObjIdTest2();
		TestBerObjectIdentifier berOID(vecOIComponents);

		QByteArray testData = getDataForTest2();
		berOID.decodeTest(vecOIComponents, testData);
	}
}


