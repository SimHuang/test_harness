#pragma once
#include <iostream>

using namespace std;

class ITest
{
public:
	virtual void test() = 0;
	ITest();
	~ITest();
};

