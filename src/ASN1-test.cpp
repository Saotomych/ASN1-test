#include "ASN1-test.h"

using namespace std;

void ASN1berGeneralizedTimeTest::runTest()
{
	cout << "ASN1berGeneralizedTime Test running" << endl;

	CBerByteArrayOutputStream berStream(50);

	char data[] = { 0x01, 0x02, 0x03 };
	QByteArray byteArray(data, sizeof(data)/sizeof(data[0]));
	CBerGeneralizedTime berGTime(byteArray);

	int length = berGTime.encode(berStream, true);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("berGeneralizedTime Test: encode length error", 5, length);

	char expecteddata[] = { 24, 0x03, 0x01, 0x02, 0x03 };
	QByteArray expectedByteArray(expecteddata, sizeof(expecteddata)/sizeof(expecteddata[0]));

	QByteArray resArray = berStream.getByteArray();

	auto itdata = resArray.begin();
	auto itexpdata =  expectedByteArray.begin();
	for (; itdata != byteArray.end() && itexpdata != expectedByteArray.end(); ++itdata, ++itexpdata)
		CPPUNIT_ASSERT_EQUAL_MESSAGE("berGeneralizedTime Test: encode data error", *itexpdata, *itdata);
}

void ASN1berIntegerTest::runTest()
{
	cout << "Test running" << endl;
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

	ASN1berGeneralizedTimeTest* bGTIMEtest = new ASN1berGeneralizedTimeTest("berGeneralizedTime Test");
	ASN1berIntegerTest* bINTtest = new ASN1berIntegerTest("berInteger Test");
	ASN1berObjectIdentifierTest* bOIDtest = new ASN1berObjectIdentifierTest("berObjectIdentifier Test");
	ASN1berOctetStringTest* bOSTRtest = new ASN1berOctetStringTest("berOctetString Test");
	ASN1berRealTest* bREALtest = new ASN1berRealTest("berReal Test");
	ASN1berIdentifierTest* bIDtest = new ASN1berIdentifierTest("berIdentifier Test");
	ASN1berLengthTest* bLENtest = new ASN1berLengthTest("berLength Test");

    // Do processing here
	CppUnit::TextTestRunner runner;
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
