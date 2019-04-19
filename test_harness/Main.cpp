#include <iostream>
#include <queue>
#include "TestHarness.h"
#include "TestFunctor.h"
#include "LinkQueue.h"
#include "FunctionList.cpp"

using namespace std;

//Test one
int testOne()
{
	cout << "This is test one" << endl;
	return 0;
}

//Test two
int testTwo()
{
	cout << "This is test two" << endl;
	return 1;
}

//Test Three
void testThree()
{
	throw exception("Error occured in test three");
}

//Test Four
void testFour()
{
	cout << "Test four";
}

/*
 The main method will instantiate a task queue. task is a struct that contains
 an id and function pointer. We can store multiple task in the queue and loop
 through the queue to execute each of them.
*/
int main() {
	queue<task> taskQueue;

	//task one
	task taskOne;
	taskOne.id = 1;
	taskOne.func = testOne;
	taskQueue.push(taskOne);

	//task two
	task taskTwo;
	taskTwo.id = 2;
	taskTwo.func = testTwo;
	taskQueue.push(taskTwo);

	//task three
	task taskThree;
	taskThree.id = 2;
	taskThree.func = testThree;
	taskQueue.push(taskThree);

	//task four
	task taskFour;
	taskFour.id = 2;
	taskFour.func = testFour;
	taskQueue.push(taskFour);

	// construct a testharness object and loop through the queue
	// execute all callable objects in the queue using the testharness executor
	TestHarness testHarness;
	for (int i = 0; i < 4; i++) {
		testHarness.executor(taskQueue.front().func);
		taskQueue.pop();
	}

	return 0;
}

