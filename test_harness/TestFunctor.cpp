#include <iostream>
#include <queue>
#include <functional>
#include "TestFunctor.h"

using namespace std;

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

int Division(int x, int y) {
	if (y == 0) {
		throw runtime_error("Dividing by zero error\n");
	}
	return x / y;
}

void divideByZero(void) {
	cout << "Bad idea to divide by zero" << endl;
	try {
		int result = Division(10, 0);
		cout << "quotient: " << result << endl;
	}
	catch (runtime_error e) {
		cout << "Exception: " << endl
			<< e.what();
	}
}

//creating and calling a queue of functions/functors/function pointers/lambdas
int TestFunctor::FunctorQueue(void) {
	//adding and using hello function in queue
	fn f1; //creating fn object f1
	f1.id = 1;
	f1.f = &hello; //assigning hello function to f1 object
	cout << "First function: hello" << endl;
	//f1.f(); //runs the hello function
	q.push(f1); //adds the function to the queue
	cout << "Calling the function from front of queue" << endl;
	fn f1called = q.front();
	f1called.f();
	q.pop();

	//adding and using divideByZero function in queue
	fn f2; 
	f2.id = 2;
	f2.f = &divideByZero; 
	cout << "Second function: divbyzero" << endl;
	f2.f(); 
	q.push(f2); 
	cout << "Calling the function from front of queue" << endl;
	fn f2called = q.front();
	q.pop();

	return 0;
}

TestFunctor::TestFunctor()
{
}


TestFunctor::~TestFunctor()
{
}
