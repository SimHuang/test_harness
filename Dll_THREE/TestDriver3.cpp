#include "pch.h"
#include "framework.h"
#include "TestDriver3.h"
#include "Test3.h"
#include <iostream>

using namespace std;

/*
	This is responsible for executing the tests
*/
TESTDRIVER_API bool test()
{
	return OutOfRange();
}

/*
	ITest is the interface between the testdriver and the test function.
	It will invoke the test() function and the test function will invoke the
	actual test and return a true or false.
*/
TESTDRIVER_API bool ITest()
{
	return test();
}
