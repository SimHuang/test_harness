#include <iostream>
#include <queue>
#include <stdexcept>
#include "TestHarness.h"
#include "TestFunctor.h"
#include "FunctionList.cpp"

using namespace std;

/*
 The main method will instantiate a task queue. task is a struct that contains
 an id and function pointer. We can store multiple task in the queue and loop
 through the queue to execute each of them.
*/
int main() {
	queue<FunctionList::task> taskQueue;

	//task one
	FunctionList::task taskOne;
	taskOne.id = 1;
	FunctionList fl;
	taskOne.func = [&] {fl.testOne();};
	taskQueue.push(taskOne);
	
	//task two
	FunctionList::task taskTwo;
	taskTwo.id = 2;
	FunctionList f2;
	taskTwo.func = [&] {f2.Divide(); };
	taskQueue.push(taskTwo);

	//task three
	FunctionList::task taskThree;
	taskThree.id = 3;
	FunctionList f3;
	taskThree.func = [&] {f3.OutOfRange(); };
	taskQueue.push(taskThree);

	//task four
	FunctionList::task taskFour;
	taskFour.id = 4;
	FunctionList f4;
	taskFour.func = [&] {f4.OverflowError(); };
	taskQueue.push(taskFour);

	//Various Test Harness objects with log level parameters
	//TestHarness testHarness;    //default logLevel = 1
	//TestHarness testHarness(2);
	TestHarness testHarness(3);
	for (int i = 0; i < 4; i++) {
		testHarness.executor(taskQueue.front().func);
		taskQueue.pop();
	}

	return 0;
}

