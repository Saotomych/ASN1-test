/*
 * berIdentifierTest.cpp
 *
 *  Created on: 14 окт. 2015 г.
 *      Author: alexey
 */

#include "berIdentifierTest.h"

void ASN1berIdentifierTest::runTest()
{
	CBerByteArrayOutputStream berOStream(50);

	CBerIdentifier berID(CBerIdentifier::APPLICATION_CLASS, CBerIdentifier::PRIMITIVE, 31);

	qint32 len = berID.encode(berOStream);

	quint8 expecteddata[] = { 0x5F, 0x1F };
	qint32 size = sizeof(expecteddata) / sizeof(expecteddata[0]);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berIdentifier Test: encode length wrong", size, len);


	QByteArray resByteArray = berOStream.getByteArray();

	for (qint32 i = 0; i < size && i < len; ++i)
		CPPUNIT_ASSERT_EQUAL_MESSAGE("ASN1berIdentifier Test: encode data wrong", expecteddata[i], quint8 (resByteArray[i]) );
}

