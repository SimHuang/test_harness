#pragma once

class TestDriver
{
public:
	TestDriver();
	~TestDriver();
	static TestDriver createInstance();
	bool test();
	bool Itest();
};

