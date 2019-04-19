#include "TestHarness.h"
#include <iostream>

using namespace std;

// Empty constructor to set log level to lowest pass/fail
TestHarness::TestHarness()
{
	logLevel = 3;
}

// Constructor to accept a log level
TestHarness::TestHarness(int log)
{
	logLevel = log;
}


TestHarness::~TestHarness()
{
}






