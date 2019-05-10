#include "pch.h"
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
 This test drive will execute the test function in the dll.
 The test function is located n Test.cpp
*/
bool TestDriver::test()
{
	// it execute the test
	cout << "This is sample test";
	return false;
}

/*
 The Itest function just acts as an interface between the testdriver
 and the test method
*/
bool TestDriver::Itest() {
	return test();
}
