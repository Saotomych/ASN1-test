/*
 * berGeneralizedTimeTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BERGENERALIZEDTIMETEST_H_
#define SRC_BERGENERALIZEDTIMETEST_H_

#include "ASN1-test.h"

class ASN1berGeneralizedTimeTest: public CppUnit::TestCase
{
public:
	ASN1berGeneralizedTimeTest(const std::string str): TestCase(str) {}
	virtual void runTest();
};


#endif /* SRC_BERGENERALIZEDTIMETEST_H_ */
