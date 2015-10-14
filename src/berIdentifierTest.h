/*
 * berIdentifierTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERIDENTIFIERTEST_H_
#define SRC_BERIDENTIFIERTEST_H_

#include "ASN1-test.h"

class ASN1berIdentifierTest: public CppUnit::TestCase
{
public:
	ASN1berIdentifierTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BERIDENTIFIERTEST_H_ */
