/*
 * berOctetStringTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BEROCTETSTRINGTEST_H_
#define SRC_BEROCTETSTRINGTEST_H_

#include "ASN1-test.h"

class ASN1berOctetStringTest: public CppUnit::TestCase
{
public:
	ASN1berOctetStringTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BEROCTETSTRINGTEST_H_ */
