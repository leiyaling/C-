//#include <iostream>
//using namespace std;

////全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout <<"a=" << a << endl;
//	cout <<"b=" << b << endl;
//	cout <<"c="<< c << endl << endl;
//}

//半缺省---必须从右往左缺省，必须连续缺省
//void Func(int a, int b = 20, int c = 30) //缺省一个
//void Func(int a, int b, int c = 30)//缺省两个
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl << endl;
//}
//int main()
//{
//	Func(1,2);//a=1,b=2,c=30
//	Func(1,2,3);//a=1,b=2,c=3
//	return 0;
//}
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//void StackInit(struct Stack* ps,int capacity = 4)
//{
//	ps->a=(int*)malloc(sizeof(int) * capacity);
//	ps->top = 0;
//	ps->capacity = capacity;
//}
//void StackPush(struct Stack* ps, int x)
//{
//	//...
//}
//int main()
//{
//	Stack st;
//	StackInit(&st);//不知道栈最多存多少个数据，用缺省参数
//	StackInit(&st,100);//知道栈最多存100个数据，显示传值，减少增容次数，提高效率
//	return 0;
//}

#include<iostream>
using namespace std;
// 1、参数类型不同
int Add(int a, int b)
{
	cout << "int Add(int a, int b)" << endl;
	return a + b;
}
double Add(double a, double b)
{
	cout << "double Add(double a, double b)" << endl;
	return a + b;
}
// 2、参数个数不同
void f()
{
	cout << "f()" << endl;
}
void f(int a)
{
 cout << "f(int a)" << endl;
}
// 3、参数类型顺序不同
void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}
int main()
{
	Add(10, 20);
	Add(10.1, 20.2);
	f();
	f(10);
	f(10, 'a');
	f('a', 10);
	return 0;
}
