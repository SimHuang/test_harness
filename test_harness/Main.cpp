#include <iostream>
#include <queue>
#include <fstream>
#include <stdexcept>
#include "TestHarness.h"
#include "TestFunctor.h"
#include "FunctionList.cpp"
//#include "TestDriver.h"
#include <Windows.h>

using namespace std;

typedef bool (*funcITest)();

/*
 The main method will instantiate a task queue. task is a struct that contains
 an id and function pointer. We can store multiple task in the queue and loop
 through the queue to execute each of them.
*/
int main() {
	/*Three TestRequest XML used for testing*/
	const string TestRequestOne = "<TestRequest>"
									"<TestElement>"
										"<TestDriver>libraryOne</TestDriver>"
										"<TestedCode>methodOne</TestedCode>"
									"</TestElement>"
							      "</TestRequest>";

	TestHarness testHarness;

	string TestOneFile;
	string TestTwoFile;
	string TestThreeFile;
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
	}
	else cout << "Unable to open file" << endl;

	//printing out part of xml for dll one
	size_t first1 = xmloutput.find("<Code1>");
	size_t last1 = xmloutput.find("</Code1>");
	//the +7 -7 gets rid of  <code> part in the string 
	TestOneFile = xmloutput.substr(first1 + 7, last1 - first1 - 7);

	//printing out part of xml for dll two
	size_t first2 = xmloutput.find("<Code2>");
	size_t last2 = xmloutput.find("</Code2>");
	TestTwoFile = xmloutput.substr(first2 + 7, last2 - first2 - 7);

	//printing out part of xml for dll three
	size_t first3 = xmloutput.find("<Code3>");
	size_t last3 = xmloutput.find("</Code3>");
	TestThreeFile = xmloutput.substr(first3 + 7, last3 - first3 - 7);

	string testRequest = "";
	//testHarness.readXML();
	cout << "\nTesting dlls: " << TestOneFile << ", " << TestTwoFile << ", " << TestThreeFile << endl;
	testRequest.append(TestOneFile).append(",").append(TestTwoFile).append(",").append(TestThreeFile);

	testHarness.execute(testRequest); //reads from xml file, loads dlls 

	return 0;
}

