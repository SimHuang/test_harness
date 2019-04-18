#pragma once
#include <iostream>

using namespace std;

class TestHarness
{

private: 

public:
	TestHarness();
	~TestHarness();

	/*
	 Accepts any callable object that accepts no arguments and returns a
	 bool predicate to indicate success or failure.
	 callable objects:
	 Functors are classes that are functions
	 Functions
	 Lamdas
	*/
	template<class CallObj>
	bool executor(CallObj& co)
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
};

