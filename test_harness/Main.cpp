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

	TestHarness testHarness;

	string testRequest = "<TestRequests>"
							"<Test>"
								"<Code1>Dll_ONE</Code1>"
							"</Test>"
							"<Test>"
								"<Code2>Dll_TWO_new</Code2>"
							"</Test>"
							"<Test>"
								"<Code3>Dll_THREE_new</Code3>"
							"</Test>"
						"</TestRequests>";

	testHarness.execute(testRequest); //takes in xml string above, parses for dlls names, loads dlls 

	return 0;
}

