#pragma once
#pragma warning(disable: 4996)
#include <string>

using namespace std;

class Logger
{
public:
	Logger();
	~Logger();
	void info(string);
	void verbose(string);
	void time();
	void log(string ddl, string testCode, bool result);
};

