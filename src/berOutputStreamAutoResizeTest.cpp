/*
 * berOutputStreamAutoResizeTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berOutputStreamAutoResizeTest.h"

void ASN1CBerByteArrayOutputStreamAutoResize::runTest()
{
	CBerByteArrayOutputStream berStream(3);

	char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
	QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
	CBerGeneralizedTime berGTime(byteArray);

//	int length = berGTime.encode(berStream, &berGTime, true);
//
//	CPPUNIT_ASSERT_EQUAL_MESSAGE("Output Stream AutoResize Test: encode length error", 7, length);

	char expecteddata[] = { 24, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05 };
	QByteArray expectedByteArray(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));

	QByteArray resByteArray = berStream.getByteArray();

	checkTestOK("Output Stream AutoResize Test: encode data error", expectedByteArray, resByteArray);
}




