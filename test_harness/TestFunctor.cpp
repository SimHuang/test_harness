#include <iostream>
#include <queue>
#include <functional>
#include "TestFunctor.h"

using namespace std;
/*
//stores a function in fn which allows us to pass in functions, lambda, function pointers, and lambdas
struct fn {
	int id;
	std::function<void()> f;
};

queue<struct fn> q;

void hello(void) {
	cout << "Hello world!" << endl;
}

int TestFunctor::FunctorQueue(void) {
	fn f1; //creating fn object f1
	f1.id = 1;
	f1.f = &hello; //assigning hello function to f1 object

	cout << "First function: " << endl;
	f1.f();

	cout << "Adding function the queue" << endl;
	q.push(f1);

	cout << "Calling the function from front of queue" << endl;
	fn f1called = q.front();
	f1called.f();
	q.pop();
}*/

TestFunctor::TestFunctor()
{
}


TestFunctor::~TestFunctor()
{
}
