/*
 * berIntegerTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERINTEGERTEST_H_
#define SRC_BERINTEGERTEST_H_

#include "ASN1-test.h"
#include "storages/berBaseType.h"
#include "storages/berIntegerStorage.h"

class CIntegerUnivPrim
{
protected:
	CBerIdentifier m_berID;

public:

	CBerInteger m_Value;

	CIntegerUnivPrim();
	CIntegerUnivPrim(qint64 val);

	quint32 encode(CBerByteArrayOutputStream& berBAOStream, bool expl);

	void testEncodeOK(char* expecteddata, int expectedlen, bool expl);
	void testDecode(char* setData, int setLen, qint64 expectedVal, bool expl);
};

class ASN1berIntegerTest: public CppUnit::TestCase
{
public:
	ASN1berIntegerTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BERINTEGERTEST_H_ */
