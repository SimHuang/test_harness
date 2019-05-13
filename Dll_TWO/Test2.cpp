#include "pch.h" // use pch.h in Visual Studio 2019
#include <utility>
#include <limits.h>
#include "Test2.h"
#include <iostream>

using namespace std;

bool OverflowError(){
	try {
		const int x = 1000; //make this a very large number to get overflow exception
		if (x > 100)
			throw std::overflow_error("Overflow error has occured");
		else {
			int array[x];
			cout << "Array is acceptable size" << endl;
		}
	}
	catch (runtime_error e) {
		return false;
	}
	return true;
}