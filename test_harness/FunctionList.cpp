#include <functional>
#include <iostream>

using namespace std;

class FunctionList {
public:
	struct task;

	struct task {
		int id;
		std::function<void()> func;
	};

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

};