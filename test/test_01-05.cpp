#include <iostream>
using namespace std;

class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};

class B : public A
{
public:
	void fun(int i)
	{
		cout << "func(int i)->" << i << endl;
	}
};

void Test()
{
	B b;
	b.fun(1);
	//b.fun(); // �������ˣ����Ե�����
	//b.A::fun();
};
int main()
{
	Test();
	return 0;
}