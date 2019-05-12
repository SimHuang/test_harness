#pragma once

#ifdef TESTDRIVER_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define TESTDRIVER_API __declspec(dllimport)
#endif

extern "C" TESTDRIVER_API bool test();
//bool Itest();

//class TestDriver
//{
//public:
	//TestDriver();
	//~TestDriver();
	//static TestDriver createInstance();
	//extern "C" TestDriver bool test();
	///bool Itest();
//};

