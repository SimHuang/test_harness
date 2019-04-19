#pragma once
#include <iostream>
#include <queue>

using namespace std;

class TestHarness
{

private:
	
public:
	int logLevel;
	TestHarness();
	TestHarness(int log);
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
		catch (const std::exception & ex) {
			//fail log level
			if (logLevel == 1) {
				cout << "Fail" << endl;
			}
			else if (logLevel == 2) {
				string error = ex.what();
				cout << error;
				cout << "Fail " + error << endl;
			}
			cout << "-------------------------------" << endl;
			return false;
		}

		//check pass log level here
		if (logLevel == 1) {
			cout << "Pass" << endl;
		}
		else if (logLevel == 2) {
			cout << "Pass: " << endl;
		}
		cout << "-------------------------------" << endl;
		return true;
	}
};

