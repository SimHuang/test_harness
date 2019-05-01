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


