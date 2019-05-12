#include "Logger.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

Logger::Logger()
{
}


Logger::~Logger()
{
}

/*
	output argument message
*/
void Logger::info(string msg)
{
	cout << msg << endl;
}

/*
	output argument message with extra information
*/
void Logger::verbose(string msg)
{
	//prints out date and time that the error occured
	std::time_t now = std::time(0);
	const char* dt = std::ctime(&now);
	cout << dt;
	cout << msg << endl;
}

void Logger::time()
{
	std::time_t now = std::time(0);
	const char* dt = std::ctime(&now);
	cout << dt << endl;
}

/*
	ddl: name of library
	testcode: name of function
	result: pass or fail
*/
void Logger::log(string dll, string testCode, bool result)
{
	if (result == true) {
		cout << "DLL: " + dll + "TestCode: " + testCode + "Result: Pass" << endl;
	}
	else {
		cout << "DLL: " + dll + "TestCode: " + testCode + "Result: Fail" << endl;
	}
	time();
}



