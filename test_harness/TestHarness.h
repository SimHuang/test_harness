#pragma once
class TestHarness
{

private: 

public:
	TestHarness();
	~TestHarness();

	template<class CallObj>
	void executor(CallObj &co);
};

