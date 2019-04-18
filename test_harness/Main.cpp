#include <iostream>
#include <queue>
#include <functional>
#include "TestHarness.h"
#include "TestFunctor.h"

using namespace std;

void testFunction() {
	cout << "This is executed by the executor";
}

//stores a function in fn which allows us to pass in functions, lambda, function pointers, and lambdas
struct fn {
	int id;
	std::function<void()> f;
};

queue<struct fn> q;

//sample helloworld program 
void hello(void) {
	cout << "Hello world!" << endl;
}

void divideByZero(void) {
	cout << "Bad idea" << endl;
}

//creating and calling a queue of functions/functors/function pointers/lambdas
int FunctorQueue(void) {
	//adding and using hello function in queue
	fn f1; //creating fn object f1
	f1.id = 1;
	f1.f = &hello; //assigning hello function to f1 object
	cout << "First function: " << endl;
	f1.f(); //runs the hello function
	q.push(f1); //adds the function to the queue
	cout << "Calling the function from front of queue" << endl;
	fn f1called = q.front();
	f1called.f();
	q.pop();

	//adding and using divideByZero function in queue
	fn f2; //creating fn object f1
	f2.id = 2;
	f2.f = &divideByZero; //assigning hello function to f1 object
	cout << "Second function: " << endl;
	f2.f(); //runs the hello function
	q.push(f2); //adds the function to the queue
	cout << "Calling the function from front of queue" << endl;
	fn f2called = q.front();
	f2called.f();
	q.pop();

	return 0;
}

/*
	Main method responsible for executing the program
*/
int main() {
	cout << "This is the main program" << endl;

	FunctorQueue();

	TestHarness testHarness;

	testHarness.executor(testFunction);

	return 0;
}

