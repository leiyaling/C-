//#include <iostream>
//using namespace std;

////ȫȱʡ
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout <<"a=" << a << endl;
//	cout <<"b=" << b << endl;
//	cout <<"c="<< c << endl << endl;
//}

//��ȱʡ---�����������ȱʡ����������ȱʡ
//void Func(int a, int b = 20, int c = 30) //ȱʡһ��
//void Func(int a, int b, int c = 30)//ȱʡ����
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
//	StackInit(&st);//��֪��ջ������ٸ����ݣ���ȱʡ����
//	StackInit(&st,100);//֪��ջ����100�����ݣ���ʾ��ֵ���������ݴ��������Ч��
//	return 0;
//}

#include<iostream>
using namespace std;
// 1���������Ͳ�ͬ
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
// 2������������ͬ
void f()
{
	cout << "f()" << endl;
}
void f(int a)
{
 cout << "f(int a)" << endl;
}
// 3����������˳��ͬ
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
