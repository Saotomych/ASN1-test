#include "ASN1-test.h"

using namespace std;

void ASN1berGeneralizedTimeTest::runTest()
{
	cout << "Test running" << endl;
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
