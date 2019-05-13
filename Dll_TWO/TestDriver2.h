#pragma once

//#ifdef TESTDRIVER_EXPORTS
//#define TESTDRIVER_API __declspec(dllexport)
//#else
//#define TESTDRIVER_API __declspec(dllimport)
//#endif

#define TESTDRIVER_API __declspec(dllexport)

extern "C" TESTDRIVER_API bool test();
extern "C" TESTDRIVER_API bool ITest();