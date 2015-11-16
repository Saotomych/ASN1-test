/*
 * berCompositeTest.cpp
 *
 *  Created on: 28 окт. 2015 г.
 *      Author: alexey
 */

#include "berCompositeTest.h"

void ASN1berCompositeTest::runTest()
{
	{
		CBerByteArrayOutputStream oStream(50);

		quint8 dataBit1[] = {1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1};
		QBitArray testdata1( sizeof(dataBit1)/sizeof(dataBit1[0]));
		for (qint32 i=0; i < testdata1.size(); ++i)
		{
			if (dataBit1[i]) testdata1.setBit(i, 1);
			else testdata1.setBit(i, 0);
		}

		quint8 dataByte1[] = {0x23, 0x45, 0x88, 0xAA, 0x55, 0xC3, 0x3C};
		QByteArray testdata2;
		for (auto val: dataByte1) testdata2.push_back(val);

		CBerInteger berInt(20);
		CBerBitString berBitStr(testdata1);
		CBerVisibleString berVisStr(testdata2);

		{


			CCompositeValue berCmpst(berInt, berBitStr, berVisStr);

			// Call encoder
			berCmpst.encode(oStream, true);

			quint8 expecteddata[] = { 0x30, 0x1E,
									  0x02, 0x01, 20,
									  0x03, 0x10, 0xFF, 0x00, 0xFF, 0, 0, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 0xFF, 0, 0xFF, 0, 0xFF,
									  0x1A, 0x07, 0x23, 0x45, 0x88, 0xAA, 0x55, 0xC3, 0x3C
			};

			quint32 expectedlen = sizeof(expecteddata) / sizeof(expecteddata[0]);

			QByteArray resByteArray = oStream.getByteArray();
			quint32 length = resByteArray.size();

			QByteArray expectedByteArray( (char*) expecteddata, expectedlen );

			QString testStr1( QString("berComposite Test encode: length error (val = %1)").arg(length) );

			CPPUNIT_ASSERT_EQUAL_MESSAGE(testStr1.toStdString(), expectedlen, length);

			QString testStr2("berComposite Test: encode data error");

			checkTestOK(testStr2.toStdString(), expectedByteArray, resByteArray);
		}

		{
			quint8 setData[] = { 0x30, 0x1E,
								0x02, 0x01, 20,
								0x03, 0x10, 0xFF, 0x00, 0xFF, 0, 0, 0xFF, 0xFF, 0xFF, 0, 0, 0xFF, 0xFF, 0, 0xFF, 0, 0xFF,
								0x1A, 0x07, 0x23, 0x45, 0x88, 0xAA, 0x55, 0xC3, 0x3C
			};

			QByteArray setByteArray; //( (char*) setData, sizeof(setData) / sizeof(setData[0]) );
			quint32 size = sizeof(setData) / sizeof(setData[0]);
			for (quint32 i=0; i < size; ++i)
				setByteArray.push_back( setData[i] );

			CBerByteArrayInputStream berInputStream(setByteArray);

			CCompositeValue berCmpst;

			berCmpst.decode(berInputStream, true);

			qint64 resInt = *( berCmpst.getValueNameInt()->getValue() );
			QBitArray resBitArray = *( berCmpst.getValueNameBitStr()->getValue() );
			QByteArray resVisString = *( berCmpst.getValueNameVisStr()->getValue() );

			qint64 expectedInt(20);
			CPPUNIT_ASSERT_EQUAL_MESSAGE("berComposite::berInteger Test decode: data error", expectedInt, resInt);

			checkTestOK("berComposite Test: BerVisibleString encode data error", testdata2, resVisString);

		}

	}

}
