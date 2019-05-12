#include "pch.h" // use pch.h in Visual Studio 2019
#include <utility>
#include <limits.h>
#include "Test.h"
#include <iostream>

using namespace std;

int Division(int x, int y) {
	if (y == 0) {
		throw runtime_error("Dividing by zero error\n");
	}
	return x / y;
}

// The test that will be executed by the test function
bool divideByZero() {
	try {
		int result = Division(10, 0);
		//cout << "quotient: " << result << endl;
	}
	catch (runtime_error e) {
		//cout << "Exception: " << endl
			//<< e.what();
		return false;
	}
	return true;
}