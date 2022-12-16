#include <iostream>
using namespace std;

template <class T>
class Stack {
public:
	Stack(int capacity = 0)
		:_capacity(capacity),
		_top(0)
	{
		_a = new int[_capacity];
	}

	~Stack()
	{
		_capacity = _top = 0;
		delete[]_a;
		_a = nullptr;
	}
private:
	int* _a;
	int _capacity;
	int _top;

};
int main()
{
	Stack <int> st1;
	Stack <double> st2;
	return 0;
}