#include "TestHarness.h"
#include <iostream>
#include <fstream>

using namespace std;

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

/*This */
void TestHarness::loadDDL(string ddl, string testedCode)
{
}

TestHarness::~TestHarness()
{
}






