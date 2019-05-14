#include "TestHarness.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include "Logger.h"

using namespace std;

typedef bool (*funcITest)();
Logger logger;

string TestOneFile;
string TestTwoFile;
string TestThreeFile;

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
 /*
int TestHarness::readXML() {
	//cout << "\nTesting reading from XML" << endl;
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
		//cout << "hopefully a string of the xml:" << endl;
		//cout << xmloutput << endl;
	}
	else cout << "Unable to open file" << endl;

	//printing out part of xml for dll one
	size_t first1 = xmloutput.find("<Code1>");
	size_t last1 = xmloutput.find("</Code1>");
	//the +7 -7 gets rid of  <code> part in the string 
	TestOneFile = xmloutput.substr(first1 + 7, last1 - first1 - 7);
	//cout << "Printing out test from xmlfile " << endl;
	//cout << TestOneFile << endl;

	//printing out part of xml for dll two
	size_t first2 = xmloutput.find("<Code2>");
	size_t last2 = xmloutput.find("</Code2>");
	TestTwoFile = xmloutput.substr(first2 + 7, last2 - first2 - 7);

	//printing out part of xml for dll three
	size_t first3 = xmloutput.find("<Code3>");
	size_t last3 = xmloutput.find("</Code3>");
	TestThreeFile = xmloutput.substr(first3 + 7 , last3 - first3 - 7);

	return 0;
}
*/
/*This function will load the DLL and execute the test */
void TestHarness::loadDDL(string ddl, string testedCode)
{
	HINSTANCE hDLL;
	funcITest Itest;
	//const char* libName = "DLL_ONE"; //should be reading argument
	const char* libName = ddl.c_str();

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
		//FreeLibrary(hDLL);
	}
	else {
		cout << "Error loading DLL";
		//cout << "\nGet Last Error : " << GetLastError();
	}
	FreeLibrary(hDLL);
}

/*
	This method will parse the testRequest string. For each
	testElement/testcode it recieved it will call loadDLL to load
	each library and execute the ITest function.
*/
void TestHarness::execute(string testRequest) {

	size_t first1 = testRequest.find("<Code1>");
	size_t last1 = testRequest.find("</Code1>");
	//the +7 -7 gets rid of  <code> part in the string 
	TestOneFile = testRequest.substr(first1 + 7, last1 - first1 - 7);

	//printing out part of xml for dll two
	size_t first2 = testRequest.find("<Code2>");
	size_t last2 = testRequest.find("</Code2>");
	TestTwoFile = testRequest.substr(first2 + 7, last2 - first2 - 7);

	//printing out part of xml for dll three
	size_t first3 = testRequest.find("<Code3>");
	size_t last3 = testRequest.find("</Code3>");
	TestThreeFile = testRequest.substr(first3 + 7, last3 - first3 - 7);

	string listOfDlls = "";
	//testHarness.readXML();
	cout << "\nTesting dlls: " << TestOneFile << ", " << TestTwoFile << ", " << TestThreeFile << endl;
	listOfDlls.append(TestOneFile).append(",").append(TestTwoFile).append(",").append(TestThreeFile);

	// for loop to loop through all DLL load it and execute the test function
	stringstream ss(listOfDlls);
	while (ss.good()) {
		string substr;
		getline(ss, substr, ','); //going through comma delimited testRequest string
		cout << "\nResult of running " << substr << endl; 
		loadDDL(substr, "testing");
	}

}


TestHarness::~TestHarness()
{
}






