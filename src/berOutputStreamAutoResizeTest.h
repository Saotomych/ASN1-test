/*
 * BerOutputStreamAutoResizeTest.h
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#ifndef SRC_BEROUTPUTSTREAMAUTORESIZETEST_H_
#define SRC_BEROUTPUTSTREAMAUTORESIZETEST_H_

#include "ASN1-test.h"

class ASN1CBerByteArrayOutputStreamAutoResize: public CppUnit::TestCase
{
public:
	ASN1CBerByteArrayOutputStreamAutoResize(const std::string str): TestCase(str) {}
	virtual void runTest();
};

#endif /* SRC_BEROUTPUTSTREAMAUTORESIZETEST_H_ */
