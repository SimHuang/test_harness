#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <ctime>
#include <stdexcept>

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
				//cout << error;
				cout << "Fail: " + error << endl;
			}
			else if (logLevel == 3) {
				string error = ex.what();
				//cout << error;
				cout << "Fail: " + error << endl;
				//prints out date and time that the error occured
				std::time_t now = std::time(0);
				const char* dt = std::ctime(&now);
				std::cout << "Error occured on: " << dt << '\n';
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
		else if (logLevel == 3) {
			cout << "Pass: " << endl;
		}
		cout << "-------------------------------" << endl;
		return true;
	}
};

