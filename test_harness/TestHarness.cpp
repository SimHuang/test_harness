#include "TestHarness.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Logger.h";

using namespace std;

typedef bool (*funcITest)();
Logger logger;

// Empty constructor to set log level to lowest pass/fail
TestHarness::TestHarness()
{
	logLevel = 1;
}

// Constructor to accept a log level
TestHarness::TestHarness(int log)
{
	logLevel = log;
}
 
int TestHarness::readXML() {
	cout << "\nTesting reading from XML" << endl;
	//reading from XML
	string xmloutput;
	ifstream myfile("XMLFile.xml");
	if (myfile.is_open()) {
		char c = myfile.get();
		xmloutput = string(1, c);
		while (myfile.good()) {
			//cout << c;
			c = myfile.get();
			xmloutput.append(string(1, c));
		}
		cout << "hopefully a string of the xml:" << endl;
		cout << xmloutput << endl;
	}
	else cout << "Unable to open file" << endl;

	//printing out part of xml string from xml file
	size_t firstx = xmloutput.find("<Code>");
	size_t lastx = xmloutput.find("</Code>");
	//the +6 -6 gets rid of the <code> part in the TestOneFile string 
	string TestOneFile = xmloutput.substr(firstx + 6 , lastx - firstx - 6);
	cout << "\nPrinting out test from xmlfile " << endl;
	cout << TestOneFile << endl;
	return 0;
}

/*This function will load the DLL and execute the test */
void TestHarness::loadDDL(string ddl, string testedCode)
{
	HINSTANCE hDLL;
	funcITest Itest;
	const char* libName = "DLL_ONE"; //should be reading argument

	hDLL = LoadLibraryEx(libName, NULL, NULL);
	if (hDLL != NULL) {
		Itest = (funcITest)GetProcAddress(hDLL, "ITest");
		if (Itest != NULL) {
			logger.time();
			bool value = Itest();
			if (value == true) {
				logger.log(ddl, testedCode, true);
			}
			else {
				logger.log(ddl, testedCode, false);
			}
		}
	}
	else {
		cout << "Error loading DLL";
	}
	FreeLibrary(hDLL);
}

/*
	This method will parse the testRequest string. For each
	testElement/testcode it recieved it will call loadDLL to load
	each library and execute the ITest function.
*/
void TestHarness::execute(string testRequest)
{
	// call readXml()

	// for loop to loop through all DLL load it and execute the test function

}


TestHarness::~TestHarness()
{
}






