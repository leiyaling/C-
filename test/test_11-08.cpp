//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//��aȡһ��������b
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	a = 20;
//	b = 30;
//
//	return 0;
//}

//int main()
//{
//	// 1�������ڶ���ʱ�����ʼ��
//	//int a = 10;
//	//int& b;
//
//	// 2��һ�����������ж������
//	//int a = 10;
//	//int& b = a;
//	//int& c = a;
//	//int& d = b;
//	//double d = 1.1;//������ͻ��ͬһ���������ﲻ��ͬ��
//
//	// 3������һ������һ��ʵ�壬�ٲ�����������ʵ��
//	int a = 10;
//	int& b = a;
//	int c = 20;
//	b = c;//��c��ֵ��b
//}
// 1������������
// _Z4swappipi
//void swap(int* p1, int* p2) // ����ַ
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//// _Z4swapriri
//void swap(int& r1, int& r2) // ������
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// _Z4swapii
//void swap(int r1, int r2)   // ��ֵ
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// �����������ɺ�������
// ����swap(x, y);����ʱ�������壬����֪�����ã���ֵ���Ǵ�����
// ������ǰ�������,���ǹ������أ����Ǵ�������
// void f();
// void f(int x = 0, int y = 0);

//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	swap(x, y);
//
//	return 0;
//}

//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}


 //�����÷���
//int& Add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(10, 20);
//	cout <<"Add(1, 2) is :" << ret << endl;
//
//	return 0;
//}
// ����x��һ����������������Ķ���
// ��ô���������ô��Σ����ٿ��������f�����в��ı�x,���龡����cosnt���ô���
//void f(int& x)
//void f(const int& x)
//{
//	cout << x << endl;
//}
//// ������
//int main()
//{
//	// Ȩ�޷Ŵ�  ������
//	//const int a = 10;
//	//int& b = a;
//
//	// Ȩ�޲��� ����
//	const int a = 10;
//	const int& b = a;
//
//	// Ȩ�޵���С ����
//	int c = 10;
//	const int& d = c;
//
//	f(a);
//	f(c);
//	f(10);
//
//	return 0;
//}
#include <iostream>
using namespace std;

inline int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int ret = Add(1, 2);
	cout << ret << endl;
	return 0;
}

//int Max(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//
//int main()
//{
//
//	cout << "Max (20,10): " << Max(20, 10) << endl;
//	cout << "Max (0,200): " << Max(0, 200) << endl;
//	cout << "Max (100,1010): " << Max(100, 1010) << endl;
//	return 0;
//}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	int x = 0, y = 1;
	Swap(x, y);
	return 0;
}
int main()
{
	const int a = 0;
	int b = 0;
	// �Զ��Ƶ�c������
	auto c = a;
	auto d = 'A';
	auto e = 10.11;

	// typeid��ӡ����������
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
}