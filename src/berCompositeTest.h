/*
 * berCompositeTest.h
 *
 *  Created on: 28 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERCOMPOSITETEST_H_
#define SRC_BERCOMPOSITETEST_H_

#include "ASN1-test.h"

class ASN1berCompositeTest: public CppUnit::TestCase
{
public:
	ASN1berCompositeTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};


#endif /* SRC_BERCOMPOSITETEST_H_ */
