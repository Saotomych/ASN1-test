/*
 * berIntegerTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERINTEGERTEST_H_
#define SRC_BERINTEGERTEST_H_

#include "ASN1-test.h"

class CIntegerUnivPrim: public CBerInteger
{
protected:
	CBerIdentifier m_berID;

public:
	CIntegerUnivPrim();
	CIntegerUnivPrim(qint64 val);

	virtual quint32 encode(CBerByteArrayOutputStream& berBAOStream, bool expl);

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
