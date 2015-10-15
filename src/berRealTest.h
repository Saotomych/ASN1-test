/*
 * berRealTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERREALTEST_H_
#define SRC_BERREALTEST_H_

#include "ASN1-test.h"

class TestBerReal: public CBerReal
{
public:
	TestBerReal();
	TestBerReal(double real);
	TestBerReal(QByteArray& code);

	void testEncodeDecodeOK(double expecteddata, bool expl);
};

class ASN1berRealTest: public CppUnit::TestCase
{
public:
	ASN1berRealTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BERREALTEST_H_ */
