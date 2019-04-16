#include "TestHarness.h"

using namespace std;

TestHarness::TestHarness()
{
}


TestHarness::~TestHarness()
{
}

/*
 Accepts any callable object that accepts no arguments and returns a
 bool predicate to indicate success or failure.
*/
template<class CallObj>
void TestHarness::executor(CallObj &co)
{
	try {
		co();
	}
	catch (...) {
		cout << "Error executing test harness test script";
		return false;
	}
	
	return true;
}



