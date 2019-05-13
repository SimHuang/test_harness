#include <iostream>
#include <queue>
#include <fstream>
#include <stdexcept>
#include "TestHarness.h"
#include "TestFunctor.h"
#include "FunctionList.cpp"
#include "TestDriver.h"
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
	//testHarness.readXML();
	//testHarness.loadDDL("abc", "123");
	testHarness.execute(""); //reads from xml file, loads dlls 
	/*----- PROJECT 1 CODE ------*/
	//queue<FunctionList::task> taskQueue;

	////printing out part of xml string
	//size_t first = TestRequestOne.find("<TestedCode>");
	//size_t last = TestRequestOne.find("</TestedCode>");
	////not sure what the +4 -4 is doing here but it is the only thing I tried that prints ouf just methodOne lol 
	//string TestOne = TestRequestOne.substr(first+sizeof(first) + 4, last - first - sizeof(first) - 4); 
	//cout << "Printing out tested code from xml string" << endl;
	//cout << TestOne << endl << endl;

	////task one
	//FunctionList::task taskOne;
	//taskOne.id = 1;
	//FunctionList fl;
	//taskOne.func = [&] {fl.testOne();};
	//taskQueue.push(taskOne);
	//
	////task two
	//FunctionList::task taskTwo;
	//taskTwo.id = 2;
	//FunctionList f2;
	//taskTwo.func = [&] {f2.Divide(); };
	//taskQueue.push(taskTwo);

	////task three
	//FunctionList::task taskThree;
	//taskThree.id = 3;
	//FunctionList f3;
	//taskThree.func = [&] {f3.OutOfRange(); };
	//taskQueue.push(taskThree);

	////task four
	//FunctionList::task taskFour;
	//taskFour.id = 4;
	//FunctionList f4;
	//taskFour.func = [&] {f4.OverflowError(); };
	//taskQueue.push(taskFour);

	////Various Test Harness objects with log level parameters
	////TestHarness testHarness;    //default logLevel = 1
	////TestHarness testHarness(2);
	//TestHarness testHarness(3);
	//for (int i = 0; i < 4; i++) {
	//	testHarness.executor(taskQueue.front().func);
	//	taskQueue.pop();
	//}


	/*
	cout << "\nTesting reading from XML" << endl;
	//reading from XML
	string xmloutput;
	ifstream myfile("XMLFile.xml");
	if (myfile.is_open()){
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
	//not sure what the +4 -6 is doing here but it is the only thing I tried that prints ouf just methodOne lol 
	string TestOneFile = xmloutput.substr(firstx + sizeof(first) + 4, lastx - firstx - sizeof(first) - 4);
	cout << "\nPrinting out test from xmlfile " << endl;
	cout << TestOneFile << endl;
	*/
	return 0;
}

