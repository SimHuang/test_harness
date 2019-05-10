#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <ctime>
#include <stdexcept>
#include "Logger.h"

using namespace std;

class TestHarness
{

private:
	
public:
	int logLevel;
	TestHarness();
	TestHarness(int log);
	~TestHarness();
	int readXML();
	void loadDDL(string dll, string testedCode);

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
		Logger logger;
		try {
			co();
		}
		catch (const std::exception & ex) {
			//log the fail and return false
			if (logLevel == 1) {
				logger.info("Fail");
			}
			else if (logLevel == 2) {
				string error = ex.what();
				logger.info("Fail" + error);
			}
			else if (logLevel == 3) {
				string error = ex.what();
				logger.verbose("Fail" + error);
			}
			cout << "-------------------------------" << endl;
			return false;
		}

		//check pass log level here
		if (logLevel == 1) {
			logger.info("Pass");
		}
		else if (logLevel == 2) {
			logger.info("Pass");
		}
		else if (logLevel == 3) {
			logger.info("Pass");
		}
		cout << "-------------------------------" << endl;
		return true;
	}
};

