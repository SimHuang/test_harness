#pragma once

#include<iostream>

using namespace std;
class AFunctor {
public:
	AFunctor();
	AFunctor(const int& x) : x_(x) {}
	void operator()(const int& y) { cout << "this is from a functor"; }
	int value() { return x_; }
private:
	int x_;
};
