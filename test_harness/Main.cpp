#include <iostream>
#include <queue>
#include <functional>
#include "TestHarness.h"
#include "TestFunctor.h"

using namespace std;

void testFunction() {
	cout << "This is executed by the executor";
}

int main() {
	cout << "This is the main program" << endl;

	//runs FunctorQueue from TestFunctor
	TestFunctor x;
	x.FunctorQueue();

	TestHarness testHarness;

	testHarness.executor(testFunction);

	return 0;
}

