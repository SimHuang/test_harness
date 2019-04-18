#include <iostream>
#include "TestHarness.h"

using namespace std;

void testFunction() {
	cout << "This is executed by the executor";
}

/*
	Main method responsible for executing the program
*/
int main() {
	cout << "This is the main program" << endl;

	TestHarness testHarness;

	testHarness.executor(testFunction);

	return 0;
}

