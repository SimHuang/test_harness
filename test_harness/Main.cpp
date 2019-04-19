#include <iostream>
#include <queue>
#include <stdexcept>
#include "TestHarness.h"
#include "TestFunctor.h"
//#include "LinkQueue.h"
#include "FunctionList.cpp"

using namespace std;

//Test one
int testOne()
{
	cout << "This is test one" << endl;
	return 0;
}

//Test two
int Divide()
{
	int quotient = 0;
	int numerator = 10;
	int denominator = 0;
	if (denominator == 0)
		throw std::overflow_error("Divide by zero exception");
	else {
		quotient = numerator / denominator;
		cout << "The quotient is: " << endl;
		return quotient;
	}
}

//Test Three
void OutOfRange()
{
	for (int n = 0; n <= 10; n++) {
		if (n > 9) //change n to > 10 to print out "end of out of range" instead of throw exception
			throw std::out_of_range("Out of range exception");
	}
	cout << "end of out of range" << endl;
}

//Test Four
void OverflowError()
{
	const int x = 1000; //make this a very large number to get overflow exception
	if (x > 100) 
		throw std::overflow_error("Overflow error has occured");
	else {
		int array[x];
		cout << "Array is acceptable size" << endl;
	}
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
	taskTwo.func = Divide;
	taskQueue.push(taskTwo);

	//task three
	task taskThree;
	taskThree.id = 2;
	taskThree.func = OutOfRange;
	taskQueue.push(taskThree);

	//task four
	task taskFour;
	taskFour.id = 2;
	taskFour.func = OverflowError;
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

