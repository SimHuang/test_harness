#pragma once
#include "ITest.h"

class TestDriver: public ITest
{
public:
	TestDriver();
	~TestDriver();
	static TestDriver createInstance();
	void test();
};

