#include "ASN1-test.h"

#include "berGeneralizedTimeTest.h"
#include "berIdentifierTest.h"
#include "berIntegerTest.h"
#include "berLengthTest.h"
#include "berObjectIdentifierTest.h"
#include "berOctetStringTest.h"
#include "berOutputStreamAutoResizeTest.h"
#include "berRealTest.h"

using namespace std;

void checkTestOK(std::string message, QByteArray& expected, QByteArray& result)
{
	auto itdata = result.begin();
	auto itexpdata =  expected.begin();
	for (; itdata != result.end() && itexpdata != expected.end(); ++itdata, ++itexpdata)
		CPPUNIT_ASSERT_EQUAL_MESSAGE(message, *itexpdata, *itdata);
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
