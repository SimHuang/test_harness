#include <iostream>
#include "TestDriver.h"

using namespace std;


TestDriver::TestDriver()
{
}


TestDriver::~TestDriver()
{
}

/*
 Test driver factory method to create instances of test driver;
*/
TestDriver TestDriver::createInstance()
{
	return TestDriver();
}

/*
 Log pass fail status of each test
*/
void TestDriver::test()
{
	cout << "This is sample test";
}
