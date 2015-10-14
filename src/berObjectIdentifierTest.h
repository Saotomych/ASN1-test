/*
 * berObjectIdentifierTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BEROBJECTIDENTIFIERTEST_H_
#define SRC_BEROBJECTIDENTIFIERTEST_H_

#include "ASN1-test.h"

class ASN1berObjectIdentifierTest: public CppUnit::TestCase
{
public:
	ASN1berObjectIdentifierTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};


#endif /* SRC_BEROBJECTIDENTIFIERTEST_H_ */
