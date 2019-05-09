#include "pch.h" // use pch.h in Visual Studio 2019
#include <utility>
#include <limits.h>
#include "Test.h"
#include <iostream>

using namespace std;

void sampleTest() {
	cout << "This is a sample test running from the DLL" << endl;
}

int Division(int x, int y) {
	if (y == 0) {
		throw runtime_error("Dividing by zero error\n");
	}
	return x / y;
}

void divideByZero() {
	cout << "Bad idea to divide by zero" << endl;
	try {
		int result = Division(10, 0);
		cout << "quotient: " << result << endl;
	}
	catch (runtime_error e) {
		cout << "Exception: " << endl
			<< e.what();
	}
}