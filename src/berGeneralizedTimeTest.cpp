/*
 * berGeneralizedTimeTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berGeneralizedTimeTest.h"

void ASN1berGeneralizedTimeTest::runTest()
{
	CBerByteArrayOutputStream berStream(50);

	char data[] = { 0x01, 0x02, 0x03 };
	QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
	CBerGeneralizedTime berGTime(byteArray);

//	int length = berGTime.encode(berStream, &berGTime, true);
//
//	CPPUNIT_ASSERT_EQUAL_MESSAGE("berGeneralizedTime Test: encode length error", 5, length);

	char expecteddata[] = { 24, 0x03, 0x01, 0x02, 0x03 };
	QByteArray expectedByteArray(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));

	QByteArray resByteArray = berStream.getByteArray();

	checkTestOK("berGeneralizedTime Test: encode data error", expectedByteArray, resByteArray);
}
