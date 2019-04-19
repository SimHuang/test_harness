#include "FunctionList.h"
#include <functional>

using namespace std;

struct task {
	int id;
	std::function<void()> func;
};