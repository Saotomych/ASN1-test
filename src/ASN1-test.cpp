#include "ASN1-test.h"

using namespace std;

void checkTest(string message, QByteArray& expected, QByteArray& result)
{
	auto itdata = result.begin();
	auto itexpdata =  expected.begin();
	for (; itdata != result.end() && itexpdata != expected.end(); ++itdata, ++itexpdata)
		CPPUNIT_ASSERT_EQUAL_MESSAGE(message, *itexpdata, *itdata);
}

CIntegerUnivPrim::CIntegerUnivPrim(qint64 val): CBerInteger(val)
{
	CBerIdentifier berID(CBerIdentifier::APPLICATION_CLASS, CBerIdentifier::PRIMITIVE, CBerIdentifier::INTEGER_TAG);
}

quint32 CIntegerUnivPrim::encode(CBerByteArrayOutputStream& berBAOStream, bool expl)
{
	quint32 codeLength = CBerInteger::encode(berBAOStream, expl);

	return codeLength;
}

void CIntegerUnivPrim::testEncode(CBerByteArrayOutputStream& berStream, char* expecteddata, int expectedlen, bool expl)
{
	int length = encode(berStream, expl);

	QString testStr1( QString("berInteger Test: encode length error (val = %1)").arg(m_Val) );
	QString testStr2( QString("berInteger Test: encode data error (val = %1)").arg(m_Val) );

	CPPUNIT_ASSERT_EQUAL_MESSAGE(testStr1.toStdString(), expectedlen, length);

	QByteArray resByteArray = berStream.getByteArray();

	QByteArray expectedByteArray( expecteddata, expectedlen );

	checkTest(testStr2.toStdString(), expectedByteArray, resByteArray);
}

void ASN1CBerByteArrayOutputStreamAutoResize::runTest()
{
	CBerByteArrayOutputStream berStream(3);

	char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
	QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
	CBerGeneralizedTime berGTime(byteArray);

	int length = berGTime.encode(berStream, true);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Output Stream AutoResize Test: encode length error", 7, length);

	char expecteddata[] = { 24, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05 };
	QByteArray expectedByteArray(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));

	QByteArray resByteArray = berStream.getByteArray();

	checkTest("Output Stream AutoResize Test: encode data error", expectedByteArray, resByteArray);
}

void ASN1berGeneralizedTimeTest::runTest()
{
	CBerByteArrayOutputStream berStream(50);

	char data[] = { 0x01, 0x02, 0x03 };
	QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
	CBerGeneralizedTime berGTime(byteArray);

	int length = berGTime.encode(berStream, true);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("berGeneralizedTime Test: encode length error", 5, length);

	char expecteddata[] = { 24, 0x03, 0x01, 0x02, 0x03 };
	QByteArray expectedByteArray(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));

	QByteArray resByteArray = berStream.getByteArray();

	checkTest("berGeneralizedTime Test: encode data error", expectedByteArray, resByteArray);
}

void ASN1berIntegerTest::runTest()
{
	CBerByteArrayOutputStream berStream(50);

	// Test 51
	{
		CIntegerUnivPrim berInt(51);
		char expecteddata[] = { 0x01, 0x33 };
		berInt.testEncode(berStream, expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 256
	{
		CIntegerUnivPrim berInt(256);
		char expecteddata[] = { 0x02, 0x01, 0x00 };
		berInt.testEncode(berStream, expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 0
	{
		CIntegerUnivPrim berInt(0);
		char expecteddata[] = { 0x01, 0x00 };
		berInt.testEncode(berStream, expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 127
	{
		CIntegerUnivPrim berInt(127);
		char expecteddata[] = { 0x01, 0x7F };
		berInt.testEncode(berStream, expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 128
	{
		CIntegerUnivPrim berInt(128);
		quint8 expecteddata[] = { 0x02, 0x00, 0x80 };
		berInt.testEncode(berStream, (char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test -128
	{
		CIntegerUnivPrim berInt(-128);
		quint8 expecteddata[] = { 0x01, 0x80 };
		berInt.testEncode(berStream, (char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test -129
	{
		CIntegerUnivPrim berInt(-129);
		quint8 expecteddata[] = { 0x02, 0xFF, 0x7F };
		berInt.testEncode(berStream, (char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), false);
	}

	// Test 51 true
	{
		CIntegerUnivPrim berInt(51);
		char expecteddata[] = { 0x02, 0x01, 0x33 };
		berInt.testEncode(berStream, expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), true);
	}

	// Test 5555 true
	{
		CIntegerUnivPrim berInt(5555);
		quint8 expecteddata[] = { 0x02, 0x02, 0x15, 0xB3 };
		berInt.testEncode(berStream, (char*) expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]), true);
	}
}

void ASN1berObjectIdentifierTest::runTest()
{
	cout << "Test running" << endl;
}

void ASN1berOctetStringTest::runTest()
{
	cout << "Test running" << endl;
}

void ASN1berRealTest::runTest()
{
	cout << "Test running" << endl;
}

void ASN1berIdentifierTest::runTest()
{
	cout << "Test running" << endl;
}

void ASN1berLengthTest::runTest()
{
	cout << "Test running" << endl;
}

int main()
{

	ASN1CBerByteArrayOutputStreamAutoResize* Streamtest = new ASN1CBerByteArrayOutputStreamAutoResize("Output Stream Test");
	ASN1berGeneralizedTimeTest* bGTIMEtest = new ASN1berGeneralizedTimeTest("berGeneralizedTime Test");
	ASN1berIntegerTest* bINTtest = new ASN1berIntegerTest("berInteger Test");
	ASN1berObjectIdentifierTest* bOIDtest = new ASN1berObjectIdentifierTest("berObjectIdentifier Test");
	ASN1berOctetStringTest* bOSTRtest = new ASN1berOctetStringTest("berOctetString Test");
	ASN1berRealTest* bREALtest = new ASN1berRealTest("berReal Test");
	ASN1berIdentifierTest* bIDtest = new ASN1berIdentifierTest("berIdentifier Test");
	ASN1berLengthTest* bLENtest = new ASN1berLengthTest("berLength Test");

    // Do processing here
	CppUnit::TextTestRunner runner;
	runner.addTest(Streamtest);
	runner.addTest(bGTIMEtest);
	runner.addTest(bINTtest);
	runner.addTest(bOIDtest);
	runner.addTest(bOSTRtest);
	runner.addTest(bREALtest);
	runner.addTest(bIDtest);
	runner.addTest(bLENtest);

	runner.run();

	std::ofstream outFile("testResult.xml");
	CppUnit::XmlOutputter outputer(&runner.result(), outFile);
	outputer.write();

	return 0;
}
