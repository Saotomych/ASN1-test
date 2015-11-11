/*
 * berObjectIdentifierTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BEROBJECTIDENTIFIERTEST_H_
#define SRC_BEROBJECTIDENTIFIERTEST_H_

#include "ASN1-test.h"

class TestBerObjectIdentifier
{
public:
	CBerObjectIdentifier m_Value;

	TestBerObjectIdentifier(QVector<qint32>& testOID);

	void encodeTest(QByteArray& testData);
	void decodeTest(QVector<qint32>& testOID, QByteArray& testData);
};

class ASN1berObjectIdentifierTest: public CppUnit::TestCase
{

	QByteArray getDataForTest1();
	QByteArray getDataForTest2();
	QVector<qint32> getDataForObjIdTest1();
	QVector<qint32> getDataForObjIdTest2();

public:
	ASN1berObjectIdentifierTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};


#endif /* SRC_BEROBJECTIDENTIFIERTEST_H_ */
