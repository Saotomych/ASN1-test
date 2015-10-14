/*
 * berLengthTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERLENGTHTEST_H_
#define SRC_BERLENGTHTEST_H_

#include "ASN1-test.h"

class ASN1berLengthTest: public CppUnit::TestCase
{
public:
	ASN1berLengthTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BERLENGTHTEST_H_ */
